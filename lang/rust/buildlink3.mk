# $NetBSD: buildlink3.mk,v 1.17 2025/03/31 16:38:43 jakllsch Exp $

BUILDLINK_TREE+=	rust

#
# DO NOT include this directly! Use rust.mk instead.
#

.if !defined(RUST_BUILDLINK3_MK)
RUST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rust+=	rust>=1.56.1
BUILDLINK_PKGSRCDIR.rust?=	../../lang/rust
BUILDLINK_PASSTHRU_DIRS+=	${PREFIX}/lib/rustlib

pkgbase:= rust
.include "../../mk/pkg-build-options.mk"
.if empty(PKG_BUILD_OPTIONS.rust:Mrust-internal-llvm)
.  include "../../lang/libunwind/buildlink3.mk"
.endif

.endif

BUILDLINK_TREE+=	-rust
