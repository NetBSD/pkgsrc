# $NetBSD: deinstall.mk,v 1.3 2006/06/05 22:49:44 jlam Exp $

# DEINSTALLDEPENDS controls whether dependencies and dependents are also
# removed when a package is de-installed.  The valid values are:
#
#    no		only the package is removed (if dependencies allow it)
#    yes	dependent packages are also removed
#    all	dependent packages and unused dependencies are also removed
#
DEINSTALLDEPENDS?=	no

######################################################################
### deinstall, su-deinstall (PUBLIC)
######################################################################
### deinstall is a public target to remove an installed package.
### It will acquire elevated privileges just-in-time.
###
.PHONY: deinstall su-deinstall
.if !target(deinstall)
deinstall: su-target
	@${PHASE_MSG} "Deinstalling for ${PKGNAME}"
.endif

su-deinstall: deinstall-pkg install-clean

MAKEFLAGS.su-deinstall=	DEINSTALLDEPENDS=${DEINSTALLDEPENDS}

######################################################################
### reinstall (PUBLIC)
######################################################################
### reinstall is a special target to re-run the install target.
### It will acquire elevated privileges just-in-time.
###
.PHONY: reinstall
.if !target(reinstall)
reinstall: install-clean install
.endif

######################################################################
### deinstall-pkg (PRIVATE, override)
######################################################################
### deinstall-pkg removes the package from the system.  This should
### be overridden per package system flavor.
###
.if !target(deinstall-pkg)
deinstall-pkg:
	@${DO_NADA}
.endif
