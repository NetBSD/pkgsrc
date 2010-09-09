# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/09/09 02:13:50 joerg Exp $

BUILDLINK_TREE+=	jbig2dec

.if !defined(JBIG2DEC_BUILDLINK3_MK)
JBIG2DEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jbig2dec+=	jbig2dec>=0.11
BUILDLINK_PKGSRCDIR.jbig2dec?=	../../graphics/jbig2dec
.endif	# JBIG2DEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-jbig2dec
