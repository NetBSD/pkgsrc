# $NetBSD: buildlink3.mk,v 1.9 2025/10/09 21:12:16 dkazankov Exp $

BUILDLINK_TREE+=	gprbuild

.if !defined(GPRBUILD_BUILDLINK3_MK)
GPRBUILD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gprbuild+=	gprbuild>=24.0.0
BUILDLINK_PKGSRCDIR.gprbuild?=		../../devel/gprbuild
BUILDLINK_DEPMETHOD.gprbuild?=		build

BUILDLINK_CONTENTS_FILTER.gprbuild=	\
	${EGREP} '(bin/gpr.*|libexec/gprbuild/gpr.*|share/gpr/.*\.gpr$$|share/gpr/manifests/.*|share/gprconfig/.*)'

BUILDLINK_FNAME_TRANSFORM.gprbuild+=	-e "s|^${BUILDLINK_DIR}/bin/gpr1|${BUILDLINK_DIR}/bin/gpr|g"

.include "../../mk/bsd.fast.prefs.mk"

# Buildlinked libraries search path
GPR_PROJECT_PATH?=	${BUILDLINK_DIR}/share/gpr
CONFIGURE_ENV+=		GPR_PROJECT_PATH=${GPR_PROJECT_PATH:Q}
MAKE_ENV+=		GPR_PROJECT_PATH=${GPR_PROJECT_PATH:Q}
INSTALL_ENV+=		GPR_PROJECT_PATH=${GPR_PROJECT_PATH:Q}

LDFLAGS+=	${COMPILER_RPATH_FLAG}'$$$$ORIGIN'

GPRBUILD_OPTIONS?=	-eL -R -cargs $${CFLAGS} -largs $${LDFLAGS} -gargs
GPRINSTALL_OPTIONS?=	#empty
BUILD_MAKE_FLAGS+=	GPRBUILD_OPTIONS=${GPRBUILD_OPTIONS:Q}
INSTALL_MAKE_FLAGS+=	GPRINSTALL_OPTIONS=${GPRINSTALL_OPTIONS:Q}

.endif

BUILDLINK_TREE+=	-gprbuild
