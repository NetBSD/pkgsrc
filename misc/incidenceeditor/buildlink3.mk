# $NetBSD: buildlink3.mk,v 1.1 2023/08/16 07:40:12 markd Exp $

BUILDLINK_TREE+=	incidenceeditor

.if !defined(INCIDENCEEDITOR_BUILDLINK3_MK)
INCIDENCEEDITOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.incidenceeditor+=	incidenceeditor>=20.04.1
BUILDLINK_PKGSRCDIR.incidenceeditor?=	../../misc/incidenceeditor

.include "../../misc/eventviews/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# INCIDENCEEDITOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-incidenceeditor
