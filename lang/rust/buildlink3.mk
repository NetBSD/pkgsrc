# $NetBSD: buildlink3.mk,v 1.10 2022/06/28 11:34:15 wiz Exp $

BUILDLINK_TREE+=	rust

#
# DO NOT include this directly! Use rust.mk instead.
#

.if !defined(RUST_BUILDLINK3_MK)
RUST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rust+=	rust>=1.20.0
BUILDLINK_ABI_DEPENDS.rust?=	rust>=1.60.0nb1
BUILDLINK_PKGSRCDIR.rust?=	../../lang/rust
BUILDLINK_PASSTHRU_DIRS+=	${PREFIX}/lib/rustlib
.endif

BUILDLINK_TREE+=	-rust
