# $NetBSD: buildlink3.mk,v 1.9 2018/01/07 13:04:06 rillig Exp $

BUILDLINK_TREE+=	libproplist

.if !defined(LIBPROPLIST_BUILDLINK3_MK)
LIBPROPLIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libproplist+=	libproplist>=0.10.1
BUILDLINK_ABI_DEPENDS.libproplist+=	libproplist>=0.10.1nb1
BUILDLINK_PKGSRCDIR.libproplist?=	../../devel/libproplist
.endif # LIBPROPLIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-libproplist
