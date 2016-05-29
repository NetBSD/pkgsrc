# $NetBSD: buildlink3.mk,v 1.2 2016/05/29 22:25:49 abs Exp $

BUILDLINK_TREE+=	libite

.if !defined(LIBITE_BUILDLINK3_MK)
LIBITE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libite+=	libite>=1.6.0
BUILDLINK_PKGSRCDIR.libite?=	../../devel/libite
.endif # LIBITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libite
