# $NetBSD: buildlink3.mk,v 1.10 2020/11/04 16:46:59 nia Exp $

BUILDLINK_TREE+=	geoclue

.if !defined(GEOCLUE_BUILDLINK3_MK)
GEOCLUE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.geoclue+=	geoclue>=0.12.0
BUILDLINK_ABI_DEPENDS.geoclue+=	geoclue>=0.12.0nb21
BUILDLINK_PKGSRCDIR.geoclue?=	../../geography/geoclue

.include "../../devel/glib2/buildlink3.mk"
.endif	# GEOCLUE_BUILDLINK3_MK

BUILDLINK_TREE+=	-geoclue
