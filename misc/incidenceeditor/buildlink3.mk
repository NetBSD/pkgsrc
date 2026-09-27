# $NetBSD: buildlink3.mk,v 1.23 2026/09/27 11:37:35 tnn Exp $

BUILDLINK_TREE+=	incidenceeditor

.if !defined(INCIDENCEEDITOR_BUILDLINK3_MK)
INCIDENCEEDITOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.incidenceeditor+=	incidenceeditor>=25.08.3
BUILDLINK_ABI_DEPENDS.incidenceeditor?=	incidenceeditor>=26.08.0nb1
BUILDLINK_PKGSRCDIR.incidenceeditor?=	../../misc/incidenceeditor

.include "../../misc/eventviews/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# INCIDENCEEDITOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-incidenceeditor
