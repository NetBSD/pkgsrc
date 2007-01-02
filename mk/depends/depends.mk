# $NetBSD: depends.mk,v 1.11 2007/01/02 17:23:41 rillig Exp $

######################################################################
### depends (PUBLIC)
######################################################################
### depends is a public target to install missing dependencies for
### the package.
###
_DEPENDS_TARGETS+=	acquire-depends-lock
_DEPENDS_TARGETS+=	${_COOKIE.depends}
_DEPENDS_TARGETS+=	release-depends-lock

.PHONY: depends
.if !target(depends)
.  if exists(${_COOKIE.depends})
depends:
	@${DO_NADA}
.  else
depends: ${_DEPENDS_TARGETS}
.  endif
.endif

.PHONY: acquire-depends-lock release-depends-lock
acquire-depends-lock: acquire-lock
release-depends-lock: release-lock

.if exists(${_COOKIE.depends})
${_COOKIE.depends}:
	@${DO_NADA}
.else
${_COOKIE.depends}: real-depends
.endif

######################################################################
### real-depends (PRIVATE)
######################################################################
### real-depends is a helper target onto which one can hook all of the
### targets that do the actual dependency installation.
###
_REAL_DEPENDS_TARGETS+=	depends-message
_REAL_DEPENDS_TARGETS+=	pre-depends-hook
_REAL_DEPENDS_TARGETS+=	depends-install
_REAL_DEPENDS_TARGETS+=	depends-cookie
_REAL_DEPENDS_TARGETS+=	error-check

.PHONY: real-depends
real-depends: ${_REAL_DEPENDS_TARGETS}

.PHONY: depends-message
depends-message:
	@${PHASE_MSG} "Installing dependencies for ${PKGNAME}"

######################################################################
### depends-install (PRIVATE, override)
######################################################################
### depends-install checks that all dependencies are installed, and will
### install any missing dependencies.  This should be overridden per
### package system flavor.
###
.if !target(depends-install)
.PHONY: depends-install
depends-install:
	@${DO_NADA}
.endif

######################################################################
### pre-depends-hook (PRIVATE, override, hook)
######################################################################
### pre-depends-hook is a generic hook target that is run just before
### dependencies are installed for depends-install.
###
.PHONY: pre-depends-hook
pre-depends-hook:
	@${DO_NADA}
