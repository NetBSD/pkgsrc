# $NetBSD: buildlink3.mk,v 1.2 2026/11/08 13:55:09 ryoon Exp $

BUILDLINK_TREE+=	metis

.if !defined(METIS_BUILDLINK3_MK)
METIS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.metis+=	metis>=5.2.1
BUILDLINK_PKGSRCDIR.metis?=	../../math/metis

.include "../../devel/gklib/buildlink3.mk"
.endif	# METIS_BUILDLINK3_MK

BUILDLINK_TREE+=	-metis
