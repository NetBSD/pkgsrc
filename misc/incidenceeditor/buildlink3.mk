# $NetBSD: buildlink3.mk,v 1.11 2025/02/12 06:45:19 ryoon Exp $

BUILDLINK_TREE+=	incidenceeditor

.if !defined(INCIDENCEEDITOR_BUILDLINK3_MK)
INCIDENCEEDITOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.incidenceeditor+=	incidenceeditor>=20.04.1
BUILDLINK_ABI_DEPENDS.incidenceeditor?=	incidenceeditor>=23.08.4nb7
BUILDLINK_PKGSRCDIR.incidenceeditor?=	../../misc/incidenceeditor

.include "../../misc/eventviews/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# INCIDENCEEDITOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-incidenceeditor
