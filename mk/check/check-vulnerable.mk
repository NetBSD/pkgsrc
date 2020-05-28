# $NetBSD: check-vulnerable.mk,v 1.6 2020/05/28 16:22:58 maya Exp $
#
# Public targets:
#
# check-vulnerable:
#	Checks for vulnerabilities in the package.
#

check-vulnerable: .PHONY _pkgformat-check-vulnerable
	@${DO_NADA}

# A package format does not need to implement this target, so provide a
# default implementation.
.if !target(_pkgformat-check-vulnerable)
_pkgformat-check-vulnerable:
	@${PHASE_MSG} "Skipping vulnerability checks."
.endif
