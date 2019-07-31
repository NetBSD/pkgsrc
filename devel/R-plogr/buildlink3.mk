# $NetBSD: buildlink3.mk,v 1.2 2019/07/31 15:32:48 brook Exp $

BUILDLINK_TREE+=	R-plogr

.if !defined(R_PLOGR_BUILDLINK3_MK)
R_PLOGR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.R-plogr+=	R-plogr>=0.2.0
BUILDLINK_DEPMETHOD.R-plogr?=	build
BUILDLINK_PKGSRCDIR.R-plogr?=	../../devel/R-plogr
.endif	# R_PLOGR_BUILDLINK3_MK

BUILDLINK_TREE+=	-R-plogr
