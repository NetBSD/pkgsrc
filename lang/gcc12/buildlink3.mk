# $NetBSD: buildlink3.mk,v 1.1 2022/06/16 15:43:55 adam Exp $

BUILDLINK_TREE+=	gcc12

.if !defined(GCC12_BUILDLINK3_MK)
GCC12_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc12+=	gcc12>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc12+=	gcc12>=12.1
BUILDLINK_PKGSRCDIR.gcc12=	../../lang/gcc12
BUILDLINK_DEPMETHOD.gcc12?=	build

BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_PREFIX.gcc12}/gcc12

BUILDLINK_FILES.gcc12=		# empty
BUILDLINK_AUTO_VARS.gcc12=	no

pkgbase := gcc12
.include "../../mk/pkg-build-options.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif

BUILDLINK_TREE+=	-gcc12
