# $NetBSD: buildlink3.mk,v 1.2 2015/01/20 15:40:14 jaapb Exp $

BUILDLINK_TREE+=	camlp4

.if !defined(CAMLP4_BUILDLINK3_MK)
CAMLP4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.camlp4+=	camlp4>=4.02.0nb1
BUILDLINK_PKGSRCDIR.camlp4?=	../../lang/camlp4
.endif	# CAMLP4_BUILDLINK3_MK

BUILDLINK_TREE+=	-camlp4
