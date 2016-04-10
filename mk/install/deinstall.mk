# $NetBSD: deinstall.mk,v 1.12 2016/04/10 15:58:02 joerg Exp $

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
.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
.  if !target(deinstall)
deinstall: su-deinstall
	@${PHASE_MSG} "Deinstalling for ${PKGNAME}"
.  endif
.else
.  if !target(deinstall)
deinstall: su-target
	@${PHASE_MSG} "Deinstalling for ${PKGNAME}"
.  endif
.endif

_SU_DEINSTALL_TARGETS=	acquire-deinstall-lock
_SU_DEINSTALL_TARGETS+=	_pkgformat-deinstall
_SU_DEINSTALL_TARGETS+=	release-deinstall-lock
su-deinstall: ${_SU_DEINSTALL_TARGETS}

.PHONY: acquire-deinstall-lock release-deinstall-lock
acquire-deinstall-lock: acquire-localbase-lock
release-deinstall-lock: release-localbase-lock

MAKEFLAGS.su-deinstall+=	DEINSTALLDEPENDS=${DEINSTALLDEPENDS}

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
