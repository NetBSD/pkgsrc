# $NetBSD: buildlink3.mk,v 1.51 2022/03/28 10:44:23 tnn Exp $

BUILDLINK_TREE+=	libksane

.if !defined(LIBKSANE_BUILDLINK3_MK)
LIBKSANE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libksane+=	libksane>=17.12.1
BUILDLINK_ABI_DEPENDS.libksane?=		libksane>=20.12.3nb5
BUILDLINK_PKGSRCDIR.libksane?=		../../graphics/libksane

.include "../../security/kwallet/buildlink3.mk"
.include "../../x11/ktextwidgets/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBKSANE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libksane
