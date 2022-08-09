# $NetBSD: build.mk,v 1.2 2022/08/09 21:45:08 wiz Exp $
#
# This Makefile fragment supports building using the CMake build tool.
#
# User-settable variables:
#
# CMAKE_GENERATOR
#	Which build tool to use.
#
#	Possible: make ninja
#	Default: make
#
# Package-settable variables:
#
# CMAKE_CONFIGURE_ARGS
#	Arguments to pass to CMake during the configure stage. Defaults
#	to CMAKE_ARGS for backwards compatibility with USE_CMAKE.
#
# CMAKE_BUILD_ARGS
#	Arguments to pass to CMake during build. Default: empty
#
# CMAKE_INSTALL_ARGS
#	Arguments to pass to CMake during installation: Default: empty
#
# CONFIGURE_DIRS
#	Directories relative to WRKSRC in which to run CMake. Usually
#	only one, the toplevel.
#
# BUILD_DIRS
#	Directories relative to WRKSRC in which to build. Defaults
#	to CONFIGURE_DIRS.
#
# TEST_DIRS
#	Directories relative to WRKSRC in which to run the tests. Defaults
#	to CONFIGURE_DIRS.
#
# INSTALL_DIRS
#	Directories relative to WRKSRC in which to run the 'install'
#	step. Defaults to CONFIGURE_DIRS.

CMAKE_REQD?=	0
.for version in ${CMAKE_REQD}
TOOL_DEPENDS+=	cmake>=${version}:../../devel/cmake
.endfor

CMAKE_CONFIGURE_ARGS?=	${CMAKE_ARGS}

CONFIGURE_ENV+=		BUILDLINK_DIR=${BUILDLINK_DIR}

CMAKE_BUILD_DIR?=	cmake-pkgsrc-build
CMAKE_GENERATOR?=	make
CMAKE_BUILD_ARGS?=	-j ${_MAKE_JOBS_N:U1}
CMAKE_INSTALL_ARGS?=	# empty
.if ${CMAKE_GENERATOR} == "ninja"
TOOL_DEPENDS+=		ninja-build-[0-9]*:../../devel/ninja-build
_CMAKE_BUILD_SYSTEM?=	Ninja
_CMAKE_BUILD_TOOL?=	ninja
.else
_CMAKE_BUILD_SYSTEM?=	Unix Makefiles
_CMAKE_BUILD_TOOL?=	${MAKE}
.endif

CONFIGURE_DIRS?=	.
BUILD_DIRS?=		${CONFIGURE_DIRS}
INSTALL_DIRS?=		${CONFIGURE_DIRS}
TEST_DIRS?=		${CONFIGURE_DIRS}

.PHONY: cmake-configure cmake-build cmake-install cmake-test

do-configure: cmake-configure
cmake-configure:
.for d in ${CONFIGURE_DIRS}
	${RUN} cd ${WRKSRC}/${d} && ${SETENV} ${CONFIGURE_ENV} cmake \
		--install-prefix ${PREFIX} \
		-B ${CMAKE_BUILD_DIR} \
		-G ${_CMAKE_BUILD_SYSTEM:Q} \
		${CMAKE_ARGS}
.endfor

do-build: cmake-build
cmake-build:
.for d in ${BUILD_DIRS}
	${RUN} cd ${WRKSRC}/${d}/${CMAKE_BUILD_DIR} && \
		${SETENV} ${MAKE_ENV} \
		${_CMAKE_BUILD_TOOL} ${CMAKE_BUILD_ARGS}
.endfor

do-test: cmake-test
cmake-test:
.for d in ${TEST_DIRS}
	${RUN} cd ${WRKSRC}/${d}/${CMAKE_BUILD_DIR} && \
		${SETENV} ${TEST_ENV} \
		${_CMAKE_BUILD_TOOL} ${CMAKE_BUILD_ARGS} ${TEST_TARGET}
.endfor

do-install: cmake-install
cmake-install:
.for d in ${INSTALL_DIRS}
	${RUN} cd ${WRKSRC}/${d}/${CMAKE_BUILD_DIR} && \
		${SETENV} ${INSTALL_ENV} \
		${_CMAKE_BUILD_TOOL} ${CMAKE_INSTALL_ARGS} ${INSTALL_TARGET}
.endfor
