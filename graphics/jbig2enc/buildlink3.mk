# $NetBSD: buildlink3.mk,v 1.2 2023/10/21 17:10:32 gdt Exp $

BUILDLINK_TREE+=	jbig2enc

.if !defined(JBIG2ENC_BUILDLINK3_MK)
JBIG2ENC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jbig2enc+=	jbig2enc>=0.29
BUILDLINK_ABI_DEPENDS.jbig2enc?=	jbig2enc>=0.29nb1
BUILDLINK_PKGSRCDIR.jbig2enc?=	../../graphics/jbig2enc

.include "../../graphics/leptonica/buildlink3.mk"
.endif	# JBIG2ENC_BUILDLINK3_MK

BUILDLINK_TREE+=	-jbig2enc
