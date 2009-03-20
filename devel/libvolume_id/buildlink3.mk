# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:24 joerg Exp $

BUILDLINK_TREE+=	libvolume_id

.if !defined(LIBVOLUME_ID_BUILDLINK3_MK)
LIBVOLUME_ID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvolume_id+=	libvolume_id>=0.81.0
BUILDLINK_PKGSRCDIR.libvolume_id?=	../../devel/libvolume_id
.endif # LIBVOLUME_ID_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvolume_id
