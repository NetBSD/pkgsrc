#!@SH@
#
# $NetBSD: greylisting-spp-wrapper.sh,v 1.1 2018/12/14 06:49:31 schmonz Exp $
#
# @PKGNAME@ wrapper for greylisting-spp.
# Skips greylisting for configured recipient addresses and domains.
# Optionally assigns a fixed "ip" in (ip,sender,recipient).
#

EXEMPTRCPTS=@PKG_SYSCONFDIR@/control/greylist/exemptrcpts
EXEMPTRCPTHOSTS=@PKG_SYSCONFDIR@/control/greylist/exemptrcpthosts

is_exempt_recipient_address() {
	[ -f "$EXEMPTRCPTS" ] \
		&& @GREP@ -qFx -- "$1" "$EXEMPTRCPTS"
}

is_exempt_recipient_domain() {
	[ -f "$EXEMPTRCPTHOSTS" ] \
		&& @GREP@ -qFx -- "$1" "$EXEMPTRCPTHOSTS"
}

main() {
	[ -n "$SMTPRCPTTO" ] || return

	rcpt="$SMTPRCPTTO"
	rcpthost=$(@ECHO@ "$rcpt" | @SED@ -e 's|.*@||')

	if is_exempt_recipient_address "$rcpt"; then
		@ECHO@ >&2 "greylisting skipped for recipient address: $rcpt"
		GL_WHITELISTED="1"; export GL_WHITELISTED
	elif is_exempt_recipient_domain "$rcpthost"; then
		@ECHO@ >&2 "greylisting skipped for recipient domain: $rcpthost"
		GL_WHITELISTED="1"; export GL_WHITELISTED
	fi

	if [ -n "$GL_WRAPPER_TCPREMOTEIP" ]; then
		TCPREMOTEIP="$GL_WRAPPER_TCPREMOTEIP"; export TCPREMOTEIP
	fi
}

main "$@"
exec @PREFIX@/bin/greylisting-spp
