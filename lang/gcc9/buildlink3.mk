# $NetBSD: buildlink3.mk,v 1.3 2023/08/14 05:24:43 wiz Exp $

BUILDLINK_TREE+=	gcc9

.if !defined(GCC9_BUILDLINK3_MK)
GCC9_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc9+=	gcc9>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc9+=	gcc9>=9.5.0nb1
BUILDLINK_PKGSRCDIR.gcc9=	../../lang/gcc9
BUILDLINK_DEPMETHOD.gcc9?=	build

BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_PREFIX.gcc9}/gcc9

BUILDLINK_FILES.gcc9=		# empty
BUILDLINK_AUTO_VARS.gcc9=	no

pkgbase := gcc9
.include "../../mk/pkg-build-options.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif

BUILDLINK_TREE+=	-gcc9
