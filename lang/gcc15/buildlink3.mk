# $NetBSD: buildlink3.mk,v 1.1 2025/07/14 17:44:53 wiz Exp $

BUILDLINK_TREE+=	gcc15

.if !defined(GCC15_BUILDLINK3_MK)
GCC15_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc15+=	gcc15>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc15+=	gcc15>=15.1
BUILDLINK_PKGSRCDIR.gcc15=	../../lang/gcc15
BUILDLINK_DEPMETHOD.gcc15?=	build

BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_PREFIX.gcc15}/gcc15

BUILDLINK_FILES.gcc15=		# empty
BUILDLINK_AUTO_VARS.gcc15=	no

pkgbase := gcc15
.include "../../mk/pkg-build-options.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif

BUILDLINK_TREE+=	-gcc15
