# $NetBSD: bsd.pkg.barrier.mk,v 1.1 2006/07/05 22:21:02 jlam Exp $

_BARRIER_COOKIE=	${WRKDIR}/.barrier_cookie

# _BARRIER_POST_TARGETS is a list of the targets that must be built after
#	the "barrier" target invokes a new make.
#
_BARRIER_PRE_TARGETS=	patch
_BARRIER_POST_TARGETS=	wrapper configure build install package

# These targets have the "main" targets as sources, and so they must also
# be barrier-aware.
#
_BARRIER_POST_TARGETS+=	test
_BARRIER_POST_TARGETS+=	reinstall repackage
_BARRIER_POST_TARGETS+=	replace

######################################################################
### barrier (PRIVATE)
######################################################################
### barrier is a helper target that can be used to separate targets
### that should be built in a new make process from being built in
### the current one.  The targets that must be built after the "barrier"
### target invokes a new make should be listed in _BARRIER_POST_TARGETS,
### and should be of the form:
###
###	.if !exists(${_BARRIER_COOKIE})
###	foo: barrier
###	.else
###	foo: foo's real source dependencies
###	.endif
###
### Note that none of foo's real source dependencies should include
### targets that occur before the barrier.
###
.PHONY: barrier
barrier: ${_BARRIER_PRE_TARGETS} barrier-cookie
.if !exists(${_BARRIER_COOKIE})
.  for _target_ in ${_BARRIER_POST_TARGETS}
.    if make(${_target_})
.      if defined(PKG_VERBOSE)
	@${PHASE_MSG} "Invoking \`\`"${_target_:Q}"'' after barrier for ${PKGNAME}"
.      endif
	${_PKG_SILENT}${_PKG_DEBUG}cd ${.CURDIR} && ${SETENV} ${BUILD_ENV} ${MAKE} ${MAKEFLAGS} ALLOW_VULNERABLE_PACKAGES= ${_target_}
.      if defined(PKG_VERBOSE)
	@${PHASE_MSG} "Leaving \`\`"${_target_:Q}"'' after barrier for ${PKGNAME}"
.      endif
.    endif
.  endfor
.endif

######################################################################
### barrier-cookie (PRIVATE)
######################################################################
### barrier-cookie creates the "barrier" cookie file.
###
barrier-cookie:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${_BARRIER_COOKIE:H}
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO} ${PKGNAME} > ${_BARRIER_COOKIE}
