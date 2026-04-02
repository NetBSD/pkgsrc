# $NetBSD: buildlink3.mk,v 1.3 2026/04/02 19:07:00 wiz Exp $

BUILDLINK_TREE+=	rust-bin

.if !defined(RUST_BIN_BUILDLINK3_MK)
RUST_BIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rust-bin+=	rust-bin>=1.85.0
BUILDLINK_PKGSRCDIR.rust-bin?=		../../lang/rust-bin
BUILDLINK_PASSTHRU_DIRS+=		${PREFIX}/lib/rustlib
.endif

BUILDLINK_TREE+=	-rust-bin
