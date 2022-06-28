# $NetBSD: buildlink3.mk,v 1.5 2022/06/28 11:34:11 wiz Exp $

BUILDLINK_TREE+=	gcc8

.if !defined(GCC8_BUILDLINK3_MK)
GCC8_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc8+=	gcc8>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc8+=	gcc8>=8.4.0nb6
BUILDLINK_PKGSRCDIR.gcc8=	../../lang/gcc8
BUILDLINK_DEPMETHOD.gcc8?=	build

BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_PREFIX.gcc8}/gcc8

BUILDLINK_FILES.gcc8=		# empty
BUILDLINK_AUTO_VARS.gcc8=	no

pkgbase := gcc8
.include "../../mk/pkg-build-options.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif

BUILDLINK_TREE+=	-gcc8
