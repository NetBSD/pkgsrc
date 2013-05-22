# $NetBSD: buildlink3.mk,v 1.1 2013/05/22 13:07:47 obache Exp $

BUILDLINK_TREE+=	crfpp

.if !defined(CRFPP_BUILDLINK3_MK)
CRFPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.crfpp+=	CRF++>=0.50
BUILDLINK_PKGSRCDIR.crfpp?=	../../textproc/CRF++
.endif # CRFPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-crfpp
