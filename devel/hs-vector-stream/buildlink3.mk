# $NetBSD: buildlink3.mk,v 1.4 2023/02/07 01:40:55 pho Exp $

BUILDLINK_TREE+=	hs-vector-stream

.if !defined(HS_VECTOR_STREAM_BUILDLINK3_MK)
HS_VECTOR_STREAM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vector-stream+=	hs-vector-stream>=0.1.0.0
BUILDLINK_ABI_DEPENDS.hs-vector-stream?=	hs-vector-stream>=0.1.0.0nb1
BUILDLINK_PKGSRCDIR.hs-vector-stream?=		../../devel/hs-vector-stream
.endif	# HS_VECTOR_STREAM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vector-stream
