# $NetBSD: depends.mk,v 1.3 2006/06/05 14:11:39 jlam Exp $

######################################################################
### depends (PUBLIC)
######################################################################
### depends is a public target to install missing dependencies for
### the package.
###
_DEPENDS_TARGETS+=	acquire-depends-lock
_DEPENDS_TARGETS+=	${_DEPENDS_COOKIE}
_DEPENDS_TARGETS+=	release-depends-lock

.PHONY: depends
depends: ${_DEPENDS_TARGETS}

.PHONY: acquire-depends-lock release-depends-lock
acquire-depends-lock: acquire-lock
release-depends-lock: release-lock

.if !exists(${_DEPENDS_COOKIE})
${_DEPENDS_COOKIE}: pre-depends-hook depends-install depends-cookie
.else
${_DEPENDS_COOKIE}:
	@${DO_NADA}
.endif

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
.if !target(pre-depends-hook)
pre-depends-hook:
	@${DO_NADA}
.endif
