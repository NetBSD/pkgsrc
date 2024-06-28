# $NetBSD: buildlink3.mk,v 1.1 2024/06/28 18:35:16 wiz Exp $

BUILDLINK_TREE+=	gcc14

.if !defined(GCC14_BUILDLINK3_MK)
GCC14_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc14+=	gcc14>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc14+=	gcc14>=14.1
BUILDLINK_PKGSRCDIR.gcc14=	../../lang/gcc14
BUILDLINK_DEPMETHOD.gcc14?=	build

BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_PREFIX.gcc14}/gcc14

BUILDLINK_FILES.gcc14=		# empty
BUILDLINK_AUTO_VARS.gcc14=	no

pkgbase := gcc14
.include "../../mk/pkg-build-options.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif

BUILDLINK_TREE+=	-gcc14
