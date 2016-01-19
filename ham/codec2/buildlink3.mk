# $NetBSD: buildlink3.mk,v 1.2 2016/01/19 04:02:07 dbj Exp $

BUILDLINK_TREE+=	codec2

.if !defined(CODEC2_BUILDLINK3_MK)
CODEC2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.codec2+=	codec2>=0.5
BUILDLINK_PKGSRCDIR.codec2?=	../../ham/codec2

BUILDLINK_INCDIRS.codec2+=	include/codec2

.endif	# CODEC2_BUILDLINK3_MK

BUILDLINK_TREE+=	-codec2
