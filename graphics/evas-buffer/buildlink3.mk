# $NetBSD: buildlink3.mk,v 1.3 2009/06/07 21:12:11 joerg Exp $

BUILDLINK_TREE+=	evas-buffer

.if !defined(EVAS_BUFFER_BUILDLINK3_MK)
EVAS_BUFFER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evas-buffer+=	evas-buffer>=0.9.9.060
BUILDLINK_PKGSRCDIR.evas-buffer?=	../../graphics/evas-buffer
.endif # EVAS_BUFFER_BUILDLINK3_MK

BUILDLINK_TREE+=	-evas-buffer
