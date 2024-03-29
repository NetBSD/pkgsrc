# $NetBSD: buildlink3.mk,v 1.5 2022/06/28 11:34:11 wiz Exp $

BUILDLINK_TREE+=	gcc7

.if !defined(GCC7_BUILDLINK3_MK)
GCC7_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc7+=	gcc7>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc7+=	gcc7>=7.5.0nb6
BUILDLINK_PKGSRCDIR.gcc7=	../../lang/gcc7
BUILDLINK_DEPMETHOD.gcc7?=	build

BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_PREFIX.gcc7}/gcc7

BUILDLINK_FILES.gcc7=		# empty
BUILDLINK_AUTO_VARS.gcc7=	no

pkgbase := gcc7
.include "../../mk/pkg-build-options.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif

BUILDLINK_TREE+=	-gcc7
