# $NetBSD: buildlink3.mk,v 1.1 2018/02/03 01:33:28 minskim Exp $

BUILDLINK_TREE+=	R-xts

.if !defined(R_XTS_BUILDLINK3_MK)
R_XTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.R-xts+=	R-xts>=0.10.1
BUILDLINK_PKGSRCDIR.R-xts?=	../../math/R-xts
.endif	# R_XTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-R-xts
