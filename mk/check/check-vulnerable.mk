# $NetBSD: check-vulnerable.mk,v 1.3 2006/07/05 09:08:35 jlam Exp $

###########################################################################
### check-vulnerable (PRIVATE, override)
###########################################################################
### check-vulnerable checks for vulnerabilities in the package.  This
### should be overridden per package system flavor.
#
.PHONY: check-vulnerable
.if !target(check-vulnerable)
check-vulnerable:
.  if defined(ALLOW_VULNERABLE_PACKAGES)
	@${DO_NADA}
.  else
	@${PHASE_MSG} "Skipping vulnerability checks."
.  endif
.endif
