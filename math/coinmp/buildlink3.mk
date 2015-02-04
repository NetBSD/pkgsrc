# $NetBSD: buildlink3.mk,v 1.1 2015/02/04 17:36:34 ryoon Exp $

BUILDLINK_TREE+=	coinmp

.if !defined(COINMP_BUILDLINK3_MK)
COINMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.coinmp+=	coinmp>=1.7.6
BUILDLINK_PKGSRCDIR.coinmp?=	../../math/coinmp
.endif	# COINMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-coinmp
