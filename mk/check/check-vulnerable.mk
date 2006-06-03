# $NetBSD: check-vulnerable.mk,v 1.1 2006/06/03 23:11:42 jlam Exp $

###########################################################################
# check-vulnerable checks for vulnerabilities in the package.  This should
# be overridden per package system flavor.
#
.PHONY: check-vulnerable
.if !target(check-vulnerable)
check-vulnerable:
	@${ECHO_MSG} "${_PKGSRC_IN} *** Skipping vulnerability checks."
.endif
