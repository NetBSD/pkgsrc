# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:04:14 rillig Exp $

BUILDLINK_TREE+=	jbig2dec

.if !defined(JBIG2DEC_BUILDLINK3_MK)
JBIG2DEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jbig2dec+=	jbig2dec>=0.11
BUILDLINK_PKGSRCDIR.jbig2dec?=		../../graphics/jbig2dec
.endif	# JBIG2DEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-jbig2dec
