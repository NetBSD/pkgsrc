# $NetBSD: buildlink3.mk,v 1.12 2018/09/11 16:13:29 gdt Exp $

BUILDLINK_TREE+=	geos

.if !defined(GEOS_BUILDLINK3_MK)
GEOS_BUILDLINK3_MK:=

#USE_LANGUAGES+=	c++11

BUILDLINK_API_DEPENDS.geos+=	geos>=2.2.3
BUILDLINK_ABI_DEPENDS.geos+=	geos>=3.3.4
BUILDLINK_PKGSRCDIR.geos?=	../../geography/geos
.endif # GEOS_BUILDLINK3_MK

BUILDLINK_TREE+=	-geos
