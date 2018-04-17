# $NetBSD: buildlink3.mk,v 1.1 2018/04/17 15:22:38 minskim Exp $

BUILDLINK_TREE+=	R-plogr

.if !defined(R_PLOGR_BUILDLINK3_MK)
R_PLOGR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.R-plogr+=	R-plogr>=0.1.1
BUILDLINK_DEPMETHOD.R-plogr?=	build
BUILDLINK_PKGSRCDIR.R-plogr?=	../../devel/R-plogr
.endif	# R_PLOGR_BUILDLINK3_MK

BUILDLINK_TREE+=	-R-plogr
