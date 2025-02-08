# $NetBSD: buildlink3.mk,v 1.3 2025/02/08 14:14:49 wiz Exp $

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

GPRBUILD_OPTIONS+=	-eL -R -largs $${LDFLAGS} -gargs
BUILD_MAKE_FLAGS+=	GPRBUILD_OPTIONS=${GPRBUILD_OPTIONS:Q}

.endif

BUILDLINK_TREE+=	-gprbuild
