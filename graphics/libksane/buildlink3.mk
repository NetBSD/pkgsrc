# $NetBSD: buildlink3.mk,v 1.76 2026/01/07 08:47:23 wiz Exp $

BUILDLINK_TREE+=	libksane

.if !defined(LIBKSANE_BUILDLINK3_MK)
LIBKSANE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libksane+=	libksane>=25.08.2
BUILDLINK_ABI_DEPENDS.libksane?=	libksane>=25.08.3nb1
BUILDLINK_PKGSRCDIR.libksane?=		../../graphics/libksane

.include "../../graphics/ksanecore/buildlink3.mk"
.include "../../security/kf6-kwallet/buildlink3.mk"
.include "../../x11/kf6-ktextwidgets/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# LIBKSANE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libksane
