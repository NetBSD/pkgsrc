# $NetBSD: depends.mk,v 1.19 2019/05/07 19:36:44 rillig Exp $

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
.  if exists(${_COOKIE.depends}) && !${_CLEANING}
depends:
	@${DO_NADA}
.  else
depends: ${_DEPENDS_TARGETS}
.  endif
.endif

.PHONY: acquire-depends-lock release-depends-lock
acquire-depends-lock: acquire-lock
release-depends-lock: release-lock

.if exists(${_COOKIE.depends}) && !${_CLEANING}
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
_REAL_DEPENDS_TARGETS+=	${_PKG_INSTALL_DEPENDS:Dpkg_install-depends}
_REAL_DEPENDS_TARGETS+=	bootstrap-depends
_REAL_DEPENDS_TARGETS+=	depends-message
_REAL_DEPENDS_TARGETS+=	pre-depends-hook
_REAL_DEPENDS_TARGETS+=	_pkgformat-install-dependencies
_REAL_DEPENDS_TARGETS+=	_pkgformat-post-install-dependencies
_REAL_DEPENDS_TARGETS+=	depends-cookie
_REAL_DEPENDS_TARGETS+=	error-check

.PHONY: real-depends
real-depends: ${_REAL_DEPENDS_TARGETS}

.PHONY: depends-message
depends-message:
	@${PHASE_MSG} "Installing dependencies for ${PKGNAME}"

######################################################################
### pre-depends-hook (PRIVATE, override, hook)
######################################################################
### pre-depends-hook is a generic hook target that is run just before
### dependencies are installed for _pkgformat-install-dependencies.
###
.PHONY: pre-depends-hook
pre-depends-hook:
	@${DO_NADA}
