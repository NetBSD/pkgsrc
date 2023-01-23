# $NetBSD: buildlink3.mk,v 1.11 2023/01/23 18:49:03 he Exp $

BUILDLINK_TREE+=	rust

#
# DO NOT include this directly! Use rust.mk instead.
#

.if !defined(RUST_BUILDLINK3_MK)
RUST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rust+=	rust>=1.56.1
BUILDLINK_PKGSRCDIR.rust?=	../../lang/rust
BUILDLINK_PASSTHRU_DIRS+=	${PREFIX}/lib/rustlib
.endif

BUILDLINK_TREE+=	-rust
