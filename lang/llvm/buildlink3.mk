# $NetBSD: buildlink3.mk,v 1.13 2021/06/13 19:02:59 wiz Exp $

BUILDLINK_TREE+=	llvm

.if !defined(LLVM_BUILDLINK3_MK)
LLVM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.llvm+=	llvm>=10.0.1
BUILDLINK_PKGSRCDIR.llvm?=	../../lang/llvm

LLVM_CONFIG_PATH?=		${BUILDLINK_PREFIX.llvm}/bin/llvm-config

BUILDLINK_FILES.llvm+=		bin/*

pkgbase := llvm
.include "../../mk/pkg-build-options.mk"
.if ${PKG_BUILD_OPTIONS.llvm:Mterminfo}
.include "../../mk/terminfo.buildlink3.mk"
.endif

.include "../../devel/zlib/buildlink3.mk"
.endif	# LLVM_BUILDLINK3_MK

BUILDLINK_TREE+=	-llvm
