# $NetBSD: buildlink3.mk,v 1.1 2026/08/10 21:41:34 wiz Exp $

BUILDLINK_TREE+=	gcc16

.if !defined(GCC16_BUILDLINK3_MK)
GCC16_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc16+=	gcc16>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc16+=	gcc16>=16.1
BUILDLINK_PKGSRCDIR.gcc16=	../../lang/gcc16
BUILDLINK_DEPMETHOD.gcc16?=	build

BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_PREFIX.gcc16}/gcc16

BUILDLINK_FILES.gcc16=		# empty
BUILDLINK_AUTO_VARS.gcc16=	no

pkgbase := gcc16
.include "../../mk/pkg-build-options.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif

BUILDLINK_TREE+=	-gcc16
