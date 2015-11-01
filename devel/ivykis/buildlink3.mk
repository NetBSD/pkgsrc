# $NetBSD: buildlink3.mk,v 1.1 2015/11/01 13:38:52 fhajny Exp $

BUILDLINK_TREE+=	ivykis

.if !defined(IVYKIS_BUILDLINK3_MK)
IVYKIS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ivykis+=	ivykis>=0.39
BUILDLINK_PKGSRCDIR.ivykis?=	../../devel/ivykis

.endif # IVYKIS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ivykis
