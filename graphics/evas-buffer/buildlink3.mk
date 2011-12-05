# $NetBSD: buildlink3.mk,v 1.5 2011/12/05 17:33:32 joerg Exp $

BUILDLINK_TREE+=	evas-buffer

.if !defined(EVAS_BUFFER_BUILDLINK3_MK)
EVAS_BUFFER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evas-buffer+=	evas-buffer>=1.1.0beta
BUILDLINK_PKGSRCDIR.evas-buffer?=	../../graphics/evas-buffer
.endif # EVAS_BUFFER_BUILDLINK3_MK

BUILDLINK_TREE+=	-evas-buffer
