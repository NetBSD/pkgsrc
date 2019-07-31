# $NetBSD: buildlink3.mk,v 1.2 2019/07/31 20:39:14 brook Exp $

BUILDLINK_TREE+=	R-xts

.if !defined(R_XTS_BUILDLINK3_MK)
R_XTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.R-xts+=	R-xts>=0.11.2
BUILDLINK_PKGSRCDIR.R-xts?=	../../math/R-xts
.endif	# R_XTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-R-xts
