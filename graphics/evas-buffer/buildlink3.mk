# $NetBSD: buildlink3.mk,v 1.6 2013/06/16 18:56:04 sno Exp $

BUILDLINK_TREE+=	evas-buffer

.if !defined(EVAS_BUFFER_BUILDLINK3_MK)
EVAS_BUFFER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evas-buffer+=	evas-buffer>=1.7.7
BUILDLINK_PKGSRCDIR.evas-buffer?=	../../graphics/evas-buffer
.endif # EVAS_BUFFER_BUILDLINK3_MK

BUILDLINK_TREE+=	-evas-buffer
