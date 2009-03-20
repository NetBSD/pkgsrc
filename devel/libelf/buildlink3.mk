# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:17 joerg Exp $

BUILDLINK_TREE+=	libelf

.if !defined(LIBELF_BUILDLINK3_MK)
LIBELF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libelf+=	libelf>=0.8.5
BUILDLINK_PKGSRCDIR.libelf?=	../../devel/libelf
.endif # LIBELF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libelf
