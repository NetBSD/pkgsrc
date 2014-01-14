# $NetBSD: depends.mk,v 1.17 2014/01/14 10:52:12 cheusov Exp $

######################################################################
### depends (PUBLIC)
######################################################################
### depends is a public target to install missing dependencies for
### the package.
###
_DEPENDS_TARGETS+=	sanity-check-depends
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

######################################################################
### sanity-check-depends (PRIVATE)
######################################################################
### sanity-check-depends is a private target to check that DEPENDS,
### TOOL_DEPENDS, BUILD_DEPENDS and CONFLICTS contain correct values
###

_SANITY_CHECK_DEPENDS_CMD=${AWK} '        \
  match($$1, /[<>][^,{}]*[*?\[\]]/) {   \
    sub(/:[^{}]*$$/, "", $$1);            \
    print "Incorrect dependency: " $$1;   \
    ex=1                                  \
  } \
  END { exit ex }'

.PHONY: sanity-check-depends
sanity-check-depends: 
	@{ ${DEPENDS:@.temp.@echo '${.temp.}';@} \
	   ${BUILD_DEPENDS:@.temp.@echo '${.temp.}';@} \
	   ${TOOL_DEPENDS:@.temp.@echo '${.temp.}';@} \
	   ${CONFLICTS:@.temp.@echo '${.temp.}';@} \
	} | ${_SANITY_CHECK_DEPENDS_CMD}
