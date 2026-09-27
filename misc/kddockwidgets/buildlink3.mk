# $NetBSD: buildlink3.mk,v 1.2 2026/09/27 11:37:36 tnn Exp $

BUILDLINK_TREE+=	kddockwidgets

.if !defined(KDDOCKWIDGETS_BUILDLINK3_MK)
KDDOCKWIDGETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kddockwidgets+=	kddockwidgets>=2.4.1
BUILDLINK_ABI_DEPENDS.kddockwidgets?=	kddockwidgets>=2.4.1nb1
BUILDLINK_PKGSRCDIR.kddockwidgets?=	../../misc/kddockwidgets

.include "../../devel/spdlog/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KDDOCKWIDGETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kddockwidgets
