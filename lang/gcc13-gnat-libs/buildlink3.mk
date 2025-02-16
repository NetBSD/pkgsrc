# $NetBSD: buildlink3.mk,v 1.2 2025/02/16 10:10:22 wiz Exp $

BUILDLINK_TREE+=	gcc13-gnat-libs

.if !defined(GCC13_GNAT_LIBS_BUILDLINK3_MK)
GCC13_GNAT_LIBS_BUILDLINK3_MK:=

.if !empty(USE_PKGSRC_GCC_RUNTIME:M[Yy][Ee][Ss])
BUILDLINK_API_DEPENDS.gcc13-gnat-libs+=	gcc13-gnat-libs>=13.2.0
.else
BUILDLINK_API_DEPENDS.gcc13-gnat-libs+=	{gcc13-gnat,gcc13-gnat-libs}>=13.2.0
.endif
BUILDLINK_PKGSRCDIR.gcc13-gnat-libs=	../../lang/gcc13-gnat-libs
BUILDLINK_DEPMETHOD.gcc13-gnat-libs?=	full

GCC_TARGET_MACHINE?=	${MACHINE_GNU_PLATFORM}

TARGET_LIBDIR.gcc13-gnat-libs=	${PREFIX}/gcc13-gnat/${GCC_TARGET_MACHINE}/lib

BUILDLINK_PASSTHRU_DIRS+=	${TARGET_LIBDIR.gcc13-gnat-libs}

BUILDLINK_FILES.gcc13-gnat-libs=	#empty
BUILDLINK_AUTO_VARS.gcc13-gnat-libs=	no
BUILDLINK_AUTO_DIRS.gcc13-gnat-libs=	no

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.endif # GCC13_GNAT_LIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc13-gnat-libs
