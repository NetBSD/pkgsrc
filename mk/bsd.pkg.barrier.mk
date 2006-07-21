# $NetBSD: bsd.pkg.barrier.mk,v 1.8 2006/07/21 14:27:56 jlam Exp $

_COOKIE.barrier=	${WRKDIR}/.barrier_cookie

# _BARRIER_PRE_TARGETS is a list of the targets that must be built before
#	the "barrier" target invokes a new make.
#
_BARRIER_PRE_TARGETS=	tools

# _BARRIER_POST_TARGETS is a list of the targets that must be built after
#	the "barrier" target invokes a new make.  This list is specially
#	ordered so that if more than one is specified on the command-line,
#	then pkgsrc will still do the right thing.
#
_BARRIER_POST_TARGETS=	wrapper
_BARRIER_POST_TARGETS+=	extract
_BARRIER_POST_TARGETS+=	patch
_BARRIER_POST_TARGETS+=	configure
_BARRIER_POST_TARGETS+=	build
_BARRIER_POST_TARGETS+=	test
_BARRIER_POST_TARGETS+=	all
_BARRIER_POST_TARGETS+=	install
_BARRIER_POST_TARGETS+=	reinstall
_BARRIER_POST_TARGETS+=	replace
_BARRIER_POST_TARGETS+=	package
_BARRIER_POST_TARGETS+=	repackage

.for _target_ in ${_BARRIER_POST_TARGETS}
.  if make(${_target_})
_BARRIER_CMDLINE_TARGETS+=	${_target_}
.  endif
.endfor

######################################################################
### barrier (PRIVATE)
######################################################################
### barrier is a helper target that can be used to separate targets
### that should be built in a new make process from being built in
### the current one.  The targets that must be built after the "barrier"
### target invokes a new make should be listed in _BARRIER_POST_TARGETS,
### and should be of the form:
###
###	.if !exists(${_COOKIE.barrier})
###	foo: barrier
###	.else
###	foo: foo's real source dependencies
###	.endif
###
### Note that none of foo's real source dependencies should include
### targets that occur before the barrier.
###

.PHONY: barrier
barrier: ${_BARRIER_PRE_TARGETS} ${_COOKIE.barrier}
.if !exists(${_COOKIE.barrier})
.  if defined(PKG_VERBOSE)
	@${PHASE_MSG} "Invoking \`\`"${_BARRIER_CMDLINE_TARGETS:Q}"'' after barrier for ${PKGNAME}"
.  endif
	${_PKG_SILENT}${_PKG_DEBUG}cd ${.CURDIR} && ${SETENV} ${PKGSRC_MAKE_ENV} ${MAKE} ${MAKEFLAGS} ALLOW_VULNERABLE_PACKAGES= ${_BARRIER_CMDLINE_TARGETS}
.  if defined(PKG_VERBOSE)
	@${PHASE_MSG} "Leaving \`\`"${_BARRIER_CMDLINE_TARGETS:Q}"'' after barrier for ${PKGNAME}"
.  endif
.endif

######################################################################
### barrier-cookie (PRIVATE)
######################################################################
### barrier-cookie creates the "barrier" cookie file.
###
${_COOKIE.barrier}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO} ${PKGNAME} > ${.TARGET}
