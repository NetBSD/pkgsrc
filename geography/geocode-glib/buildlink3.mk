# $NetBSD: buildlink3.mk,v 1.3 2023/08/14 05:24:29 wiz Exp $

BUILDLINK_TREE+=	geocode-glib

.if !defined(GEOCODE_GLIB_BUILDLINK3_MK)
GEOCODE_GLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.geocode-glib+=	geocode-glib>=3.26.2
BUILDLINK_ABI_DEPENDS.geocode-glib?=	geocode-glib>=3.26.2nb8
BUILDLINK_PKGSRCDIR.geocode-glib?=	../../geography/geocode-glib

.include "../../devel/glib2/buildlink3.mk"
.endif	# GEOCODE_GLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-geocode-glib
