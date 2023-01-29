# $NetBSD: buildlink3.mk,v 1.58 2023/01/29 21:14:42 ryoon Exp $

BUILDLINK_TREE+=	libksane

.if !defined(LIBKSANE_BUILDLINK3_MK)
LIBKSANE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libksane+=	libksane>=17.12.1
BUILDLINK_ABI_DEPENDS.libksane?=		libksane>=22.08.1nb2
BUILDLINK_PKGSRCDIR.libksane?=		../../graphics/libksane

.include "../../graphics/ksanecore/buildlink3.mk"
.include "../../security/kwallet/buildlink3.mk"
.include "../../x11/ktextwidgets/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBKSANE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libksane
