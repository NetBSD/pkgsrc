# $NetBSD: buildlink3.mk,v 1.4 2023/11/12 13:22:45 wiz Exp $

BUILDLINK_TREE+=	incidenceeditor

.if !defined(INCIDENCEEDITOR_BUILDLINK3_MK)
INCIDENCEEDITOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.incidenceeditor+=	incidenceeditor>=20.04.1
BUILDLINK_ABI_DEPENDS.incidenceeditor?=	incidenceeditor>=23.04.3nb3
BUILDLINK_PKGSRCDIR.incidenceeditor?=	../../misc/incidenceeditor

.include "../../misc/eventviews/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# INCIDENCEEDITOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-incidenceeditor
