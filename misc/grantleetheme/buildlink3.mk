# $NetBSD: buildlink3.mk,v 1.8 2024/11/01 00:52:44 wiz Exp $

BUILDLINK_TREE+=	grantleetheme

.if !defined(GRANTLEETHEME_BUILDLINK3_MK)
GRANTLEETHEME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.grantleetheme+=	grantleetheme>=20.04.1
BUILDLINK_ABI_DEPENDS.grantleetheme?=	grantleetheme>=23.08.4nb4
BUILDLINK_PKGSRCDIR.grantleetheme?=	../../misc/grantleetheme

.include "../../devel/grantlee-qt5/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# GRANTLEETHEME_BUILDLINK3_MK

BUILDLINK_TREE+=	-grantleetheme
