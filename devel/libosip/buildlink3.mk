# $NetBSD: buildlink3.mk,v 1.13 2018/01/07 13:04:06 rillig Exp $

BUILDLINK_TREE+=	libosip2

.if !defined(LIBOSIP2_BUILDLINK3_MK)
LIBOSIP2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libosip2+=	libosip2>=3.6.0
BUILDLINK_ABI_DEPENDS.libosip2+=	libosip2>=3.6.0
BUILDLINK_PKGSRCDIR.libosip2?=		../../devel/libosip
.endif # LIBOSIP2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libosip2
