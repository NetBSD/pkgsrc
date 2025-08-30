# $NetBSD: buildlink3.mk,v 1.5 2025/08/30 22:45:25 wiz Exp $

BUILDLINK_TREE+=	jbig2enc

.if !defined(JBIG2ENC_BUILDLINK3_MK)
JBIG2ENC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jbig2enc+=	jbig2enc>=0.29
BUILDLINK_ABI_DEPENDS.jbig2enc+=	jbig2enc>=0.30nb2
BUILDLINK_PKGSRCDIR.jbig2enc?=		../../graphics/jbig2enc

.include "../../graphics/leptonica/buildlink3.mk"
.endif	# JBIG2ENC_BUILDLINK3_MK

BUILDLINK_TREE+=	-jbig2enc
