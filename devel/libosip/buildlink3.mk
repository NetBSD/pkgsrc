# $NetBSD: buildlink3.mk,v 1.12 2011/12/19 13:04:45 schwarz Exp $

BUILDLINK_TREE+=	libosip2

.if !defined(LIBOSIP2_BUILDLINK3_MK)
LIBOSIP2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libosip2+=	libosip2>=3.6.0
BUILDLINK_ABI_DEPENDS.libosip2+=	libosip2>=3.6.0
BUILDLINK_PKGSRCDIR.libosip2?=	../../devel/libosip
.endif # LIBOSIP2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libosip2
