# $NetBSD: test.mk,v 1.23 2019/10/13 11:08:10 rillig Exp $
#
# After the "build" phase, many packages provide some sort of self-test
# that can be run on the not-yet installed package. To enable these
# tests, the package must define TEST_TARGET or override the do-test
# target. Additionally, the pkgsrc user must define PKGSRC_RUN_TEST.
#
# User-settable variables:
#
# PKGSRC_RUN_TEST
#	(See defaults/mk.conf)
#
# Package-settable variables:
#
# TEST_TARGET is the name of the ${MAKE} target, provided by the
#	package, which enables the tests to be executed
#
# TEST_DIRS is the list of directories in which to run the tests.
#	If the directories are relative paths, then they are
#	assumed to be relative to ${WRKSRC}.
#
# TEST_ENV is the shell environment that is exported to the make
#       process.
#
# TEST_MAKE_FLAGS is the list of arguments that is passed to the make
#	process, in addition to the usual MAKE_FLAGS.
#
# Variables defined by this file:
#
# TEST_MAKE_CMD
#	This command sets the proper environment for the test phase
#	and runs make(1) on it. It takes a list of make targets and
#	flags as argument.
#
# See also:
#	mk/build/build.mk
#
# Keywords: test check
#

_VARGROUPS+=		test
_USER_VARS.test=	PKGSRC_RUN_TEST
_PKG_VARS.test=		TEST_TARGET TEST_DIRS TEST_ENV TEST_MAKE_FLAGS
_USE_VARS.test=		BUILD_DIRS MAKE_ENV MAKE_FLAGS MAKEFLAGS MAKE_FILE \
			RECURSIVE_MAKE INTERACTIVE_STAGE BATCH WRKSRC
_IGN_VARS.test=		_* PKGNAME .CURDIR
_SORTED_VARS.test=	*_ENV
_LISTED_VARS.test=	*_DIRS *_FLAGS

TEST_DIRS?=		${BUILD_DIRS}
TEST_ENV+=		${MAKE_ENV}
TEST_MAKE_FLAGS?=	# none

TEST_MAKE_CMD= \
	${PKGSRC_SETENV} ${TEST_ENV}					\
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${TEST_MAKE_FLAGS}	\
			-f ${MAKE_FILE}

######################################################################
### test (PUBLIC)
######################################################################
### build is a public target to build the sources from the package.
###
_TEST_TARGETS+=	check-vulnerable
_TEST_TARGETS+=	build
_TEST_TARGETS+=	test-depends
_TEST_TARGETS+=	acquire-test-lock
_TEST_TARGETS+=	${_COOKIE.test}
_TEST_TARGETS+=	release-test-lock

.PHONY: test
.if !target(test)
.  if exists(${_COOKIE.test}) && !${_CLEANING}
test:
	@${DO_NADA}
.  elif defined(_PKGSRC_BARRIER)
test: ${_TEST_TARGETS}
.  else
test: barrier
.  endif
.endif

.PHONY: acquire-test-lock release-test-lock
acquire-test-lock: acquire-lock
release-test-lock: release-lock

.if exists(${_COOKIE.test}) && !${_CLEANING}
${_COOKIE.test}:
	@${DO_NADA}
.else
${_COOKIE.test}: real-test
.endif

######################################################################
### retest (PUBLIC)
######################################################################
### retest is a special target to re-run the test target.
###
.PHONY: retest
retest: test-clean
	${RUN} ${RECURSIVE_MAKE} ${MAKEFLAGS} test

######################################################################
### real-test (PRIVATE)
######################################################################
### real-test is a helper target onto which one can hook all of the
### targets that do the actual test of the built objects.
###
_REAL_TEST_TARGETS+=	test-check-interactive
_REAL_TEST_TARGETS+=	test-message
_REAL_TEST_TARGETS+=	pre-test
_REAL_TEST_TARGETS+=	do-test
_REAL_TEST_TARGETS+=	post-test
_REAL_TEST_TARGETS+=	test-cookie
_REAL_TEST_TARGETS+=	error-check

.PHONY: real-test
real-test: ${_REAL_TEST_TARGETS}

.PHONY: test-message
test-message:
	@${PHASE_MSG} "Testing for ${PKGNAME}"

######################################################################
### test-check-interactive (PRIVATE)
######################################################################
### test-check-interactive checks whether we must do an interactive
### test or not.
###
test-check-interactive: .PHONY
.if !empty(INTERACTIVE_STAGE:Mtest) && defined(BATCH)
	@${ERROR_MSG} "The test stage of this package requires user interaction"
	@${ERROR_MSG} "Please test manually with:"
	@${ERROR_MSG} "    \"cd ${.CURDIR} && ${MAKE} test\""
	${RUN} ${FALSE}
.else
	@${DO_NADA}
.endif

######################################################################
### pre-test, do-test, post-test (PUBLIC, override)
######################################################################
### {pre,do,post}-test are the heart of the package-customizable
### test targets, and may be overridden within a package Makefile.
###
.PHONY: pre-test do-test post-test

.if !target(do-test)
.  if defined(TEST_TARGET) && !empty(TEST_TARGET)
do-test:
.    for dir in ${TEST_DIRS}
	${RUN}${_ULIMIT_CMD} cd ${WRKSRC} && cd ${dir} \
	&& ${TEST_MAKE_CMD} ${TEST_TARGET}
.    endfor
.  else
do-test:
	@${DO_NADA}
.  endif
.endif

.if !target(pre-test)
pre-test:
	@${DO_NADA}
.endif

.if !target(post-test)
post-test:
	@${DO_NADA}
.endif

######################################################################
### test-cookie (PRIVATE)
######################################################################
### test-cookie creates the "test" cookie file.
###
.PHONY: test-cookie
test-cookie:
	${RUN}${TEST} ! -f ${_COOKIE.test} || ${FALSE}
	${RUN}${MKDIR} ${_COOKIE.test:H}
	${RUN}${ECHO} ${PKGNAME} > ${_COOKIE.test}

######################################################################
### test-clean (PRIVATE)
######################################################################
### test-clean removes the state files for the "test" and
### later phases so that the "test" target may be re-invoked.
###
.PHONY: test-clean
test-clean:
	${RUN} ${RM} -f ${_COOKIE.test}
