# $NetBSD: buildlink3.mk,v 1.1 2024/07/07 10:56:19 wiz Exp $

BUILDLINK_TREE+=	rust-bin

.if !defined(RUST_BIN_BUILDLINK3_MK)
RUST_BIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rust-bin+=	rust-bin>=1.56.1<1.77
BUILDLINK_PKGSRCDIR.rust-bin?=		../../lang/rust176-bin
BUILDLINK_PASSTHRU_DIRS+=		${PREFIX}/lib/rustlib
.endif

BUILDLINK_TREE+=	-rust-bin
