# $NetBSD: buildlink3.mk,v 1.1 2021/05/13 18:57:27 khorben Exp $

BUILDLINK_TREE+=	nng

.if !defined(NNG_BUILDLINK3_MK)
NNG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nng+=	nng>=1.4.0
BUILDLINK_PKGSRCDIR.nng?=	../../net/nng
.endif	# NNG_BUILDLINK3_MK

BUILDLINK_TREE+=	-nng
