# $NetBSD: buildlink3.mk,v 1.3 2020/11/29 23:10:25 dbj Exp $

BUILDLINK_TREE+=	codec2

.if !defined(CODEC2_BUILDLINK3_MK)
CODEC2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.codec2+=	codec2>=0.9.2
BUILDLINK_PKGSRCDIR.codec2?=	../../ham/codec2

BUILDLINK_INCDIRS.codec2+=	include/codec2

.endif	# CODEC2_BUILDLINK3_MK

BUILDLINK_TREE+=	-codec2
