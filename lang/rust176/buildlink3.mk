# $NetBSD: buildlink3.mk,v 1.1 2024/07/07 10:43:29 wiz Exp $

BUILDLINK_TREE+=	rust

#
# DO NOT include this directly! Use rust.mk instead.
#

.if !defined(RUST_BUILDLINK3_MK)
RUST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rust+=	rust>=1.56.1<1.77
BUILDLINK_PKGSRCDIR.rust?=	../../lang/rust176
BUILDLINK_PASSTHRU_DIRS+=	${PREFIX}/lib/rustlib
.endif

BUILDLINK_TREE+=	-rust
