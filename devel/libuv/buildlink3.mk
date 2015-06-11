# $NetBSD: buildlink3.mk,v 1.1 2015/06/11 13:32:35 fhajny Exp $

BUILDLINK_TREE+=	libuv

.if !defined(LIBUV_BUILDLINK3_MK)
LIBUV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libuv+=	libuv>=1.6
BUILDLINK_PKGSRCDIR.libuv?=	../../devel/libuv

.endif # LIBUV_BUILDLINK3_MK

BUILDLINK_TREE+=	-libuv
