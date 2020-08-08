# $NetBSD: buildlink3.mk,v 1.1 2020/08/08 23:12:18 brook Exp $

BUILDLINK_TREE+=	R-sf

.if !defined(R_SF_BUILDLINK3_MK)
R_SF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.R-sf+=	R-sf>=0.9.5
BUILDLINK_PKGSRCDIR.R-sf?=	../../geography/R-sf

.endif	# R_SF_BUILDLINK3_MK

BUILDLINK_TREE+=	-R-sf
