# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:38 joerg Exp $

BUILDLINK_TREE+=	evas-buffer

.if !defined(EVAS_BUFFER_BUILDLINK3_MK)
EVAS_BUFFER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evas-buffer+=	evas-buffer>=0.9.9.050
BUILDLINK_PKGSRCDIR.evas-buffer?=	../../graphics/evas-buffer
.endif # EVAS_BUFFER_BUILDLINK3_MK

BUILDLINK_TREE+=	-evas-buffer
