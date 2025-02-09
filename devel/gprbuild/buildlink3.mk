# $NetBSD: buildlink3.mk,v 1.4 2025/02/09 13:33:26 wiz Exp $

BUILDLINK_TREE+=	gprbuild

.if !defined(GPRBUILD_BUILDLINK3_MK)
GPRBUILD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gprbuild+=	gprbuild>=24.0.0
BUILDLINK_PKGSRCDIR.gprbuild=		../../devel/gprbuild
BUILDLINK_DEPMETHOD.gprbuild?=		build

# GPRbuild does similar things in its own way
BUILDLINK_AUTO_VARS.gprbuild=	no
BUILDLINK_AUTO_DIRS.gprbuild=	no

BUILDLINK_FILES.gprbuild=	bin/gpr* libexec/gprbuild/*
BUILDLINK_FILES.gprbuild+=	share/gpr/_default.gpr share/gpr/manifests/gprbuild
BUILDLINK_FILES.gprbuild+=	share/gprconfig/*

BUILDLINK_CONTENTS_FILTER.gprbuild=	\
	${EGREP} '(bin/gpr.*|libexec/gprbuild/gpr.*|share/gpr/.*\.gpr$$|share/gpr/manifests/.*|share/gprconfig/.*)'

TARGET_LIBDIR.gprbuild=	${PREFIX}/lib

# Buildlinked libraries search path
GPR_PROJECT_PATH?=	${BUILDLINK_DIR}/share/gpr
CONFIGURE_ENV+=		GPR_PROJECT_PATH=${GPR_PROJECT_PATH:Q}
MAKE_ENV+=		GPR_PROJECT_PATH=${GPR_PROJECT_PATH:Q}
INSTALL_ENV+=		GPR_PROJECT_PATH=${GPR_PROJECT_PATH:Q}

LDFLAGS+=	${COMPILER_RPATH_FLAG}'$$$$ORIGIN'

GPRBUILD_OPTIONS?=	-eL -R -largs $${LDFLAGS} -gargs
GPRINSTALL_OPTIONS?=	#empty
BUILD_MAKE_FLAGS+=	GPRBUILD_OPTIONS=${GPRBUILD_OPTIONS:Q}
INSTALL_MAKE_FLAGS+=	GPRINSTALL_OPTIONS=${GPRINSTALL_OPTIONS:Q}

SUBST_CLASSES+=			gprbuildlink
SUBST_STAGE.gprbuildlink=	pre-configure
SUBST_FILES.gprbuildlink=	default.cgpr
SUBST_MESSAGE.gprbuildlink=	Set directory path in config file
SUBST_VARS.gprbuildlink=	WRKDIR

BUILDLINK_TARGETS+=	gprbuild-make-config-project

.PHONY: gprbuild-make-config-project
gprbuild-make-config-project:
	${RUN} ${CP} ${BUILDLINK_PKGSRCDIR.gprbuild}/files/buildlink.cgpr ${WRKSRC}/default.cgpr

.endif

BUILDLINK_TREE+=	-gprbuild
