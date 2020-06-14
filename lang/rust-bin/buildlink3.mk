# $NetBSD: buildlink3.mk,v 1.1 2020/06/14 15:33:28 nia Exp $

BUILDLINK_TREE+=	rust-bin

.if !defined(RUST_BIN_BUILDLINK3_MK)
RUST_BIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rust-bin+=	rust-bin>=1.20.0
BUILDLINK_PKGSRCDIR.rust-bin?=		../../lang/rust-bin
BUILDLINK_PASSTHRU_DIRS+=		${PREFIX}/lib/rustlib
.endif

BUILDLINK_TREE+=	-rust-bin
