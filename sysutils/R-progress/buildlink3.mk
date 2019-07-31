# $NetBSD: buildlink3.mk,v 1.1 2019/07/31 13:40:18 brook Exp $

BUILDLINK_TREE+=	R-progress

.if !defined(R_PROGRESS_BUILDLINK3_MK)
R_PROGRESS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.R-progress+=	R-progress>=1.2.2
BUILDLINK_PKGSRCDIR.R-progress?=	../../sysutils/R-progress
.endif	# R_PROGRESS_BUILDLINK3_MK

BUILDLINK_TREE+=	-R-progress
