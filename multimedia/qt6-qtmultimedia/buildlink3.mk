# $NetBSD: buildlink3.mk,v 1.2 2023/01/29 21:14:53 ryoon Exp $

BUILDLINK_TREE+=	qt6-qtmultimedia

.if !defined(QT6_QTMULTIMEDIA_BUILDLINK3_MK)
QT6_QTMULTIMEDIA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtmultimedia+=	qt6-qtmultimedia>=6.4.1
BUILDLINK_ABI_DEPENDS.qt6-qtmultimedia?=		qt6-qtmultimedia>=6.4.1nb1
BUILDLINK_PKGSRCDIR.qt6-qtmultimedia?=		../../multimedia/qt6-qtmultimedia

pkgbase := qt6-qtmultimedia
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.qt6-qtmultimedia:Mgstreamer}
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.endif
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTMULTIMEDIA_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtmultimedia
