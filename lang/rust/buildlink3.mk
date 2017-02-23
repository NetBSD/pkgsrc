# $NetBSD: buildlink3.mk,v 1.2 2017/02/23 09:35:16 jperkin Exp $

BUILDLINK_TREE+=	rust

.if !defined(RUST_BUILDLINK3_MK)
RUST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rust+=	rust>=1.15.1
BUILDLINK_PKGSRCDIR.rust?=	../../lang/rust

BUILDLINK_PASSTHRU_DIRS+=	${PREFIX}/lib/rustlib
.endif

BUILDLINK_TREE+=	-rust
