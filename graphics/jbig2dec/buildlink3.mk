# $NetBSD: buildlink3.mk,v 1.5 2023/10/19 14:46:00 wiz Exp $

BUILDLINK_TREE+=	jbig2dec

.if !defined(JBIG2DEC_BUILDLINK3_MK)
JBIG2DEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jbig2dec+=	jbig2dec>=0.16
BUILDLINK_ABI_DEPENDS.jbig2dec?=	jbig2dec>=0.19nb2
BUILDLINK_PKGSRCDIR.jbig2dec?=		../../graphics/jbig2dec
.endif	# JBIG2DEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-jbig2dec
