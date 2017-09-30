# $NetBSD: buildlink3.mk,v 1.3 2017/09/30 04:42:43 ryoon Exp $

BUILDLINK_TREE+=	rust

.if !defined(RUST_BUILDLINK3_MK)
RUST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rust+=	rust>=1.20.0
BUILDLINK_PKGSRCDIR.rust?=	../../lang/rust

BUILDLINK_PASSTHRU_DIRS+=	${PREFIX}/lib/rustlib
.endif

BUILDLINK_TREE+=	-rust
