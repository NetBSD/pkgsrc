# $NetBSD: buildlink3.mk,v 1.5 2022/11/23 16:18:55 adam Exp $

BUILDLINK_TREE+=	libkcompactdisc

.if !defined(LIBKCOMPACTDISC_BUILDLINK3_MK)
LIBKCOMPACTDISC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkcompactdisc+=	libkcompactdisc>=20.04.1
BUILDLINK_ABI_DEPENDS.libkcompactdisc?=	libkcompactdisc>=22.08.1nb1
BUILDLINK_PKGSRCDIR.libkcompactdisc?=	../../multimedia/libkcompactdisc

.include "../../devel/kcoreaddons/buildlink3.mk"
.include "../../devel/ki18n/buildlink3.mk"
.include "../../multimedia/phonon-qt5/buildlink3.mk"
.include "../../sysutils/solid/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBKCOMPACTDISC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkcompactdisc
