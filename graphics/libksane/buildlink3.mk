# $NetBSD: buildlink3.mk,v 1.41 2020/06/02 08:22:43 adam Exp $

BUILDLINK_TREE+=	libksane

.if !defined(LIBKSANE_BUILDLINK3_MK)
LIBKSANE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libksane+=	libksane>=17.12.1
BUILDLINK_ABI_DEPENDS.libksane?=		libksane>=19.12.1nb4
BUILDLINK_PKGSRCDIR.libksane?=		../../graphics/libksane

.include "../../security/kwallet/buildlink3.mk"
.include "../../x11/ktextwidgets/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBKSANE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libksane
