# $NetBSD: buildlink3.mk,v 1.3 2019/04/17 08:27:20 adam Exp $

BUILDLINK_TREE+=	jbig2dec

.if !defined(JBIG2DEC_BUILDLINK3_MK)
JBIG2DEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jbig2dec+=	jbig2dec>=0.16
BUILDLINK_PKGSRCDIR.jbig2dec?=		../../graphics/jbig2dec
.endif	# JBIG2DEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-jbig2dec
