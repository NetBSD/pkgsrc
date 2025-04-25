# $NetBSD: buildlink3.mk,v 1.1 2025/04/25 19:35:10 dkazankov Exp $

BUILDLINK_TREE+=	gcc14-gnat-libs

.if !defined(GCC14_GNAT_LIBS_BUILDLINK3_MK)
GCC14_GNAT_LIBS_BUILDLINK3_MK:=

.if !empty(USE_PKGSRC_GCC_RUNTIME:M[Yy][Ee][Ss])
BUILDLINK_API_DEPENDS.gcc14-gnat-libs+=	gcc14-gnat-libs>=14.1.0
.else
BUILDLINK_API_DEPENDS.gcc14-gnat-libs+=	{gcc14-gnat,gcc14-gnat-libs}>=14.1.0
.endif
BUILDLINK_PKGSRCDIR.gcc14-gnat-libs=	../../lang/gcc14-gnat-libs
BUILDLINK_DEPMETHOD.gcc14-gnat-libs?=	full

GCC_TARGET_MACHINE?=	${MACHINE_GNU_PLATFORM}

TARGET_LIBDIR.gcc14-gnat-libs=	${PREFIX}/gcc14-gnat/${GCC_TARGET_MACHINE}/lib

BUILDLINK_PASSTHRU_DIRS+=	${TARGET_LIBDIR.gcc14-gnat-libs}

BUILDLINK_FILES.gcc14-gnat-libs=	#empty
BUILDLINK_AUTO_VARS.gcc14-gnat-libs=	no
BUILDLINK_AUTO_DIRS.gcc14-gnat-libs=	no

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.endif # GCC14_GNAT_LIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc14-gnat-libs
