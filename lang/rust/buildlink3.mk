# $NetBSD: buildlink3.mk,v 1.4 2020/05/18 16:17:20 nia Exp $

BUILDLINK_TREE+=	rust

.if !defined(RUST_BUILDLINK3_MK)
RUST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rust+=	rust>=1.20.0

.include "../../lang/rust/type.mk"
.if ${RUST_TYPE} != "bin"
BUILDLINK_PKGSRCDIR.rust?=	../../lang/rust
.else
BUILDLINK_PKGSRCDIR.rust?=	../../lang/rust-bin
.endif

BUILDLINK_PASSTHRU_DIRS+=	${PREFIX}/lib/rustlib
.endif

BUILDLINK_TREE+=	-rust
