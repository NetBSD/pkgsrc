#!@SH@
#
# $NetBSD: greylisting-spp-with-exemptions.sh,v 1.1 2018/11/13 16:34:58 schmonz Exp $
#
# @PKGNAME@ wrapper to skip greylisting for certain recipient
# addresses and domains.
# Requires greylisting-spp.
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
		export GL_WHITELISTED="1"
	elif is_exempt_recipient_domain "$rcpthost"; then
		@ECHO@ >&2 "greylisting skipped for recipient domain: $rcpthost"
		export GL_WHITELISTED="1"
	fi
}

main "$@"
exec @PREFIX@/bin/greylisting-spp
