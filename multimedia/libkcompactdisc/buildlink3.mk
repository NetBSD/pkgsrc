# $NetBSD: buildlink3.mk,v 1.21 2026/02/06 10:05:27 wiz Exp $

BUILDLINK_TREE+=	libkcompactdisc

.if !defined(LIBKCOMPACTDISC_BUILDLINK3_MK)
LIBKCOMPACTDISC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkcompactdisc+=	libkcompactdisc>=25.08.2
BUILDLINK_ABI_DEPENDS.libkcompactdisc?=	libkcompactdisc>=25.08.3nb2
BUILDLINK_PKGSRCDIR.libkcompactdisc?=	../../multimedia/libkcompactdisc

.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../multimedia/phonon-qt6/buildlink3.mk"
.include "../../sysutils/kf6-solid/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# LIBKCOMPACTDISC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkcompactdisc
