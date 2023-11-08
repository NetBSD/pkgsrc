# $NetBSD: buildlink3.mk,v 1.3 2023/11/08 13:20:06 wiz Exp $

BUILDLINK_TREE+=	grantleetheme

.if !defined(GRANTLEETHEME_BUILDLINK3_MK)
GRANTLEETHEME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.grantleetheme+=	grantleetheme>=20.04.1
BUILDLINK_ABI_DEPENDS.grantleetheme?=	grantleetheme>=23.04.3nb2
BUILDLINK_PKGSRCDIR.grantleetheme?=	../../misc/grantleetheme

.include "../../devel/grantlee-qt5/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# GRANTLEETHEME_BUILDLINK3_MK

BUILDLINK_TREE+=	-grantleetheme
