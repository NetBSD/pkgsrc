# $NetBSD: buildlink3.mk,v 1.1 2023/04/06 12:15:55 joerg Exp $

BUILDLINK_TREE+=	jbig2enc

.if !defined(JBIG2ENC_BUILDLINK3_MK)
JBIG2ENC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jbig2enc+=	jbig2enc>=0.29
BUILDLINK_PKGSRCDIR.jbig2enc?=	../../graphics/jbig2enc

.include "../../graphics/leptonica/buildlink3.mk"
.endif	# JBIG2ENC_BUILDLINK3_MK

BUILDLINK_TREE+=	-jbig2enc
