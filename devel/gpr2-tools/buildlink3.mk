# $NetBSD: buildlink3.mk,v 1.4 2025/11/26 10:22:56 dkazankov Exp $

BUILDLINK_TREE+=	gpr2-tools

.if !defined(GPR2TOOLS_BUILDLINK3_MK)
GPR2TOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gpr2-tools+=	gpr2-tools>=25.0.0
BUILDLINK_PKGSRCDIR.gpr2-tools?=	../../devel/gpr2-tools
BUILDLINK_DEPMETHOD.gpr2-tools?=	build

BUILDLINK_CONTENTS_FILTER.gpr2-tools=	\
    ${EGREP} '(bin/.*|share/gpr/manifests/.*)'

BUILDLINK_FNAME_TRANSFORM.gprbuild+=	-e "s|^${BUILDLINK_DIR}/bin/gpr2|${BUILDLINK_DIR}/bin/gpr|g"

.include "../../mk/bsd.fast.prefs.mk"

# Buildlinked packages search path
GPR_PROJECT_PATH?=	${BUILDLINK_DIR}/share/gpr
GPRBUILD_OPTIONS?=	-eL -R -cargs $${CFLAGS} -largs -L ${BUILDLINK_DIR}/lib $${LDFLAGS} ${COMPILER_RPATH_FLAG}'$$$$ORIGIN' -gargs
GPRINSTALL_OPTIONS?=	#empty

ALL_ENV+=		GPR_PROJECT_PATH=${GPR_PROJECT_PATH:Q}
BUILD_MAKE_FLAGS+=	GPRBUILD_OPTIONS=${GPRBUILD_OPTIONS:Q}
INSTALL_MAKE_FLAGS+=	GPRINSTALL_OPTIONS=${GPRINSTALL_OPTIONS:Q}

.endif

BUILDLINK_TREE+=	-gpr2-tools
