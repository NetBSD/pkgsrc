#!@SH@
#
# $NetBSD: tinydyndns-passwd.sh,v 1.2 2020/10/19 07:15:55 schmonz Exp $
#
# @PKGNAME@ program to update password for a dynamic-DNS hostname.

TINYDYN_ETC="@PKG_SYSCONFDIR@"
TINYDYN_DOMAIN=$(@HEAD@ -1 ${TINYDYN_ETC}/domain)
TINYDYN_PASSWD="${TINYDYN_ETC}/passwd"
TINYDYN_PASSWDTMP="${TINYDYN_ETC}/passwd{new}"
TINYDYN_USER=@TINYDYN_USER@
TINYDYN_UID=$(@ID@ -u ${TINYDYN_USER})
TINYDYN_GID=$(@ID@ -g ${TINYDYN_USER})
TINYDYN_SHELL="@NOLOGIN@"

passwd_exists_for() {
	local _hostname
	_hostname=$1
	@GREP@ "^${_hostname}:" ${TINYDYN_PASSWD} >/dev/null 2>/dev/null
}

passwd_hash() {
	local _password
	_password=$1
	echo "$1" | @PREFIX@/bin/tinydyndns-pwhash
}

passwd_add() {
	local _hostname _password
	_hostname=$1
	_password=$2
	_hashed_password=$(passwd_hash "${_password}")
	@CAT@ ${TINYDYN_PASSWD} >${TINYDYN_PASSWDTMP} 2>/dev/null
	echo "${_hostname}:${_hashed_password}:${TINYDYN_UID}:${TINYDYN_GID}::${TINYDYN_ETC}:${TINYDYN_SHELL}" \
		>>${TINYDYN_PASSWDTMP}
}

passwd_update() {
	local _hostname _password
	_hostname=$1
	_password=$2
	_hashed_password=$(passwd_hash "${_password}")
	@SED@ -e \
		"s|^${_hostname}:.*$|${_hostname}:${_hashed_password}:${TINYDYN_UID}:${TINYDYN_GID}::${TINYDYN_ETC}:${TINYDYN_SHELL}|g" \
		${TINYDYN_PASSWD} >${TINYDYN_PASSWDTMP}
}

dyndns_add() {
	local _hostname
	_hostname=$1
	( cd ${TINYDYN_ETC}; @PREFIX@/bin/tinydyndns-data add ${_hostname}.${TINYDYN_DOMAIN} )
}

main() {
	if [ -z "$1" -o -z "$2" ]; then
		echo "Usage: $0 hostname password" >&2
		return 1
	fi

	dyn_hostname=$1
	dyn_password=$2

	if passwd_exists_for "${dyn_hostname}"; then
		passwd_update "${dyn_hostname}" "${dyn_password}"
	else
		passwd_add "${dyn_hostname}" "${dyn_password}"
	fi
	@MV@ -f ${TINYDYN_PASSWDTMP} ${TINYDYN_PASSWD}
	@CHMOD@ 600 ${TINYDYN_PASSWD}

	dyndns_add "${dyn_hostname}"
}

main "$@"
exit $?
