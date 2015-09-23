# $NetBSD: buildlink3.mk,v 1.1 2015/09/23 03:57:32 tnn Exp $

BUILDLINK_TREE+=	metis

.if !defined(METIS_BUILDLINK3_MK)
METIS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.metis+=	metis>=4.0.3
BUILDLINK_PKGSRCDIR.metis?=	../../math/metis
BUILDLINK_DEPMETHOD.metis?=	build
.endif	# METIS_BUILDLINK3_MK

BUILDLINK_TREE+=	-metis
