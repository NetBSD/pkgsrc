# $NetBSD: buildlink3.mk,v 1.1 2016/09/06 10:36:49 jperkin Exp $

BUILDLINK_TREE+=	rust

.if !defined(RUST_BUILDLINK3_MK)
RUST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rust+=	rust>=0.11.0
BUILDLINK_PKGSRCDIR.rust?=	../../lang/rust

BUILDLINK_PASSTHRU_DIRS+=	${PREFIX}/lib/rustlib
.endif

BUILDLINK_TREE+=	-rust
