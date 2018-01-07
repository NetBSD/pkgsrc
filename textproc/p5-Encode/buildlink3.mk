# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:04:35 rillig Exp $

BUILDLINK_TREE+=	p5-Encode

.if !defined(P5_ENCODE_BUILDLINK3_MK)
P5_ENCODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.p5-Encode+=	p5-Encode>=2.89nb1
BUILDLINK_PKGSRCDIR.p5-Encode?=		../../textproc/p5-Encode
.endif	# P5_ENCODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-p5-Encode
