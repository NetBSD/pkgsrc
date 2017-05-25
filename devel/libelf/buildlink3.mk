# $NetBSD: buildlink3.mk,v 1.8 2017/05/25 06:01:04 dholland Exp $

BUILDLINK_TREE+=	libelf

.if !defined(LIBELF_BUILDLINK3_MK)
LIBELF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libelf+=	libelf>=0.8.5
BUILDLINK_PKGSRCDIR.libelf?=	../../devel/libelf
BUILDLINK_INCDIRS.libelf?=	include/libelf
.endif # LIBELF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libelf
