# $NetBSD: bsd.pkg.barrier.mk,v 1.16 2008/02/07 21:36:13 rillig Exp $

_COOKIE.barrier=	${WRKDIR}/.barrier_cookie

# _BARRIER_PRE_TARGETS is a list of the targets that must be built before
#	the "barrier" target invokes a new make.
#
_BARRIER_PRE_TARGETS=	checksum-phase makedirs depends

# _BARRIER_POST_TARGETS is a list of the targets that must be built after
#	the "barrier" target invokes a new make.  This list is specially
#	ordered so that if more than one is specified on the command-line,
#	then pkgsrc will still do the right thing.
#

# FIXME: why is wrapper before extract?
_BARRIER_POST_TARGETS=	tools
_BARRIER_POST_TARGETS+=	wrapper
_BARRIER_POST_TARGETS+=	extract
_BARRIER_POST_TARGETS+=	patch
_BARRIER_POST_TARGETS+=	configure
_BARRIER_POST_TARGETS+=	build build-env
_BARRIER_POST_TARGETS+=	test
_BARRIER_POST_TARGETS+=	all
_BARRIER_POST_TARGETS+=	install
_BARRIER_POST_TARGETS+=	reinstall
_BARRIER_POST_TARGETS+=	replace
_BARRIER_POST_TARGETS+=	package
_BARRIER_POST_TARGETS+=	repackage
_BARRIER_POST_TARGETS+=	package-install

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
###	.if !defined(_PKGSRC_BARRIER)
###	foo: barrier
###	.else
###	foo: foo's real source dependencies
###	.endif
###
### Note that none of foo's real source dependencies should include
### targets that occur before the barrier.
###

.PHONY: barrier-error-check
barrier-error-check: error-check

.PHONY: barrier
barrier: ${_BARRIER_PRE_TARGETS} ${_COOKIE.barrier}
.if !defined(_PKGSRC_BARRIER)
.  if defined(PKG_VERBOSE)
	@${PHASE_MSG} "Invoking \`\`"${_BARRIER_CMDLINE_TARGETS:Q}"'' after barrier for ${PKGNAME}"
.  endif
	${RUN}					\
	cd ${.CURDIR}							\
	&& ${RECURSIVE_MAKE} ${MAKEFLAGS} _PKGSRC_BARRIER=yes ALLOW_VULNERABLE_PACKAGES= ${_BARRIER_CMDLINE_TARGETS} \
	|| {								\
		exitcode="$$?";						\
		${RECURSIVE_MAKE} ${MAKEFLAGS} _PKGSRC_BARRIER=yes barrier-error-check; \
		exit "$$exitcode";					\
	}
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
	${RUN}${MKDIR} ${.TARGET:H}
	${RUN}${ECHO} ${PKGNAME} > ${.TARGET}
