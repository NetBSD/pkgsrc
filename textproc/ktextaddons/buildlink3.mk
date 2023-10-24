# $NetBSD: buildlink3.mk,v 1.3 2023/10/24 22:11:18 wiz Exp $

BUILDLINK_TREE+=	ktextaddons

.if !defined(KTEXTADDONS_BUILDLINK3_MK)
KTEXTADDONS_BUILDLINK3_MK:=


BUILDLINK_API_DEPENDS.ktextaddons+=	ktextaddons>=1.3.2
BUILDLINK_ABI_DEPENDS.ktextaddons?=	ktextaddons>=1.3.2nb1
BUILDLINK_PKGSRCDIR.ktextaddons?=	../../textproc/ktextaddons

.include "../../archivers/karchive/buildlink3.mk"
.include "../../devel/kcoreaddons/buildlink3.mk"
.include "../../devel/ki18n/buildlink3.mk"
.include "../../security/qt5-qtkeychain/buildlink3.mk"
.include "../../x11/kconfigwidgets/buildlink3.mk"
.include "../../x11/kxmlgui/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KTEXTADDONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ktextaddons
