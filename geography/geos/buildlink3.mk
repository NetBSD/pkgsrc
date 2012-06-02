# $NetBSD: buildlink3.mk,v 1.11 2012/06/02 16:27:30 drochner Exp $

BUILDLINK_TREE+=	geos

.if !defined(GEOS_BUILDLINK3_MK)
GEOS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.geos+=	geos>=2.2.3
BUILDLINK_ABI_DEPENDS.geos+=	geos>=3.3.4
BUILDLINK_PKGSRCDIR.geos?=	../../geography/geos
.endif # GEOS_BUILDLINK3_MK

BUILDLINK_TREE+=	-geos
