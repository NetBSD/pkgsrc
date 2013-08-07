# $NetBSD: buildlink3.mk,v 1.1.1.1 2013/08/07 04:54:06 agc Exp $

BUILDLINK_TREE+=	libcurvecpr

.if !defined(LIBCURVECPR_BUILDLINK3_MK)
LIBCURVECPR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcurvecpr+=	libcurvecpr>=20130806
BUILDLINK_PKGSRCDIR.libcurvecpr?=	../../security/libcurvecpr

.endif	# LIBCURVECPR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcurvecpr
