# $NetBSD: gprbuild.mk,v 1.3 2025/02/09 13:33:26 wiz Exp $
#
# This Makefile fragment supports building using the GPRbuild tool.
#
# Package-settable variables:
#
# GPRBUILD_PROJECT_FILE
#	The path to the project file that is processed by GPRbuild and GPRInstall executables.
#	Default: MAKE_FILE
#
# GPRBUILD_ENV
#	The shell environment that is exported to the GPRbuild process.
#	Default: MAKE_ENV
#
# GPRBUILD_ARGS
#	Arguments to pass to GPRbuild during build.
#	Default: -j0 -p
#
# BUILD_DIRS
#	Directories in which to build.
#	Default: WRKSRC
#
# GPRINSTALL_ENV
#	The shell environment that is exported to the GPRinstall process.
#	Default: INSTALL_ENV
#
# GPRINSTALL_ARGS
#	Arguments to pass to GPRinstall during installation:
#	Default: --mode=usage -p --prefix=${DESTDIR}${PREFIX}
#
# INSTALL_DIRS
#	Directories relative in which to run the 'install' step.
#	Default: WRKSRC

.include "../../devel/gprbuild/buildlink3.mk"

GPRBUILD_PROJECT_FILE?=	${MAKE_FILE}
GPRBUILD_ENV?=		${MAKE_ENV}
GPRINSTALL_ENV?=	${INSTALL_ENV}
GPRINSTALL_ENV+=	${GPRBUILD_ENV}

GPRBUILD_ARGS?=		-j0 -p ${GPRBUILD_OPTIONS}
GPRINSTALL_ARGS?=	--mode=usage -p --prefix=${DESTDIR}${PREFIX} ${GPRINSTALL_OPTIONS}

GPRBUILD_TOOL=		gprbuild
GPRINSTALL_TOOL=	gprinstall

do-build: gprbuild-build
do-install: gprbuild-install

.if !target(gprbuild-build)
.PHONY: gprbuild-build
gprbuild-build:
	for dir in ${BUILD_DIRS}; do \
	    set -e; \
	    cd $$dir && \
		${PKGSRC_SETENV} ${GPRBUILD_ENV} \
		${GPRBUILD_TOOL} ${GPRBUILD_ARGS} -P ${GPRBUILD_PROJECT_FILE}; \
	done
.endif

.if !target(gprbuild-install)
.PHONY: gprbuild-install
gprbuild-install:
	for dir in ${INSTALL_DIRS}; do \
	    set -e; \
	    cd $$dir && \
		${PKGSRC_SETENV} ${GPRINSTALL_ENV} \
		${GPRINSTALL_TOOL} ${GPRINSTALL_ARGS} -P ${GPRBUILD_PROJECT_FILE}; \
	done
.endif
