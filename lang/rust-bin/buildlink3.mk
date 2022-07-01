# $NetBSD: buildlink3.mk,v 1.2 2022/07/01 07:00:28 pin Exp $

BUILDLINK_TREE+=	rust-bin

.if !defined(RUST_BIN_BUILDLINK3_MK)
RUST_BIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rust-bin+=	rust-bin>=1.56.1
BUILDLINK_PKGSRCDIR.rust-bin?=		../../lang/rust-bin
BUILDLINK_PASSTHRU_DIRS+=		${PREFIX}/lib/rustlib
.endif

BUILDLINK_TREE+=	-rust-bin
