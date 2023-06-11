# $NetBSD: buildlink3.mk,v 1.1 2023/06/11 02:22:30 mef Exp $

BUILDLINK_TREE+=	R-testthat

.if !defined(R_TESTTHAT_BUILDLINK3_MK)
R_TESTTHAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.R-testthat+=	R-testthat>=3.1.8
BUILDLINK_PKGSRCDIR.R-testthat?=	../../devel/R-testthat

.endif # R_TESTTHAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-R-testthat
