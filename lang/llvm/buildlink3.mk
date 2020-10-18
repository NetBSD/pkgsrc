# $NetBSD: buildlink3.mk,v 1.12 2020/10/18 15:51:09 maya Exp $

BUILDLINK_TREE+=	llvm

.if !defined(LLVM_BUILDLINK3_MK)
LLVM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.llvm+=	llvm>=10.0.1
BUILDLINK_PKGSRCDIR.llvm?=	../../lang/llvm

LLVM_CONFIG_PATH?=		${BUILDLINK_PREFIX.llvm}/bin/llvm-config

pkgbase := llvm
.include "../../mk/pkg-build-options.mk"
.if ${PKG_BUILD_OPTIONS.llvm:Mterminfo}
.include "../../mk/terminfo.buildlink3.mk"
.endif

.include "../../devel/zlib/buildlink3.mk"
.endif	# LLVM_BUILDLINK3_MK

BUILDLINK_TREE+=	-llvm
