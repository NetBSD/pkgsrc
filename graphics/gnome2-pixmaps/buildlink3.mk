# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 04:40:49 xtraeme Exp $
#
# This Makefile fragment is included by packages that use gnome2-pixmaps.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GNOME2_PIXMAPS_BUILDLINK3_MK:=	${GNOME2_PIXMAPS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome2-pixmaps
.endif

.if !empty(GNOME2_PIXMAPS_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			gnome2-pixmaps
BUILDLINK_DEPENDS.gnome2-pixmaps+=	gnome2-pixmaps>=2.4.1.1
BUILDLINK_PKGSRCDIR.gnome2-pixmaps?=	../../graphics/gnome2-pixmaps

.endif # GNOME2_PIXMAPS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
