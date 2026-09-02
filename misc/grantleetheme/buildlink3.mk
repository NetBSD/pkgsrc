# $NetBSD: buildlink3.mk,v 1.20 2026/09/02 19:03:28 wiz Exp $

BUILDLINK_TREE+=	grantleetheme

.if !defined(GRANTLEETHEME_BUILDLINK3_MK)
GRANTLEETHEME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.grantleetheme+=	grantleetheme>=25.08.2
BUILDLINK_ABI_DEPENDS.grantleetheme?=	grantleetheme>=25.08.3nb5
BUILDLINK_PKGSRCDIR.grantleetheme?=	../../misc/grantleetheme

.include "../../net/kf6-knewstuff/buildlink3.mk"
.include "../../textproc/kf6-ktexttemplate/buildlink3.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# GRANTLEETHEME_BUILDLINK3_MK

BUILDLINK_TREE+=	-grantleetheme
