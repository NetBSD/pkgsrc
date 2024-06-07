# $NetBSD: kf6.mk,v 1.3 2024/06/07 23:57:17 markd Exp $
# used by archivers/kf6-karchive/Makefile
# used by devel/kf6-kbookmarks/Makefile
# used by devel/kf6-kcmutils/Makefile
# used by devel/kf6-kcolorscheme/Makefile
# used by devel/kf6-kconfig/Makefile
# used by devel/kf6-kcoreaddons/Makefile
# used by devel/kf6-kcrash/Makefile
# used by devel/kf6-kdeclarative/Makefile
# used by devel/kf6-kdoctools/Makefile
# used by devel/kf6-ki18n/Makefile
# used by devel/kf6-kidletime/Makefile
# used by devel/kf6-kio/Makefile
# used by devel/kf6-kitemmodels/Makefile
# used by devel/kf6-knotifications/Makefile
# used by devel/kf6-knotifyconfig/Makefile
# used by devel/kf6-kpackage/Makefile
# used by devel/kf6-kparts/Makefile
# used by devel/kf6-kpeople/Makefile
# used by devel/kf6-kpty/Makefile
# used by devel/kf6-krunner/Makefile
# used by devel/kf6-kservice/Makefile
# used by devel/kf6-ktexteditor/Makefile
# used by devel/kf6-purpose/Makefile
# used by devel/kf6-threadweaver/Makefile
# used by graphics/breeze-icons/Makefile
# used by graphics/kf6-kiconthemes/Makefile
# used by graphics/kf6-kimageformats/Makefile
# used by graphics/kf6-kplotting/Makefile
# used by graphics/kf6-ksvg/Makefile
# used by graphics/kf6-prison/Makefile
# used by misc/kf6-attica/Makefile
# used by misc/kf6-kcontacts/Makefile
# used by misc/kf6-kdav/Makefile
# used by misc/kf6-kquickcharts/Makefile
# used by misc/kf6-kunitconversion/Makefile
# used by net/kf6-kdnssd/Makefile
# used by net/kf6-knewstuff/Makefile
# used by security/kf6-kauth/Makefile
# used by security/kf6-kdesu/Makefile
# used by security/kf6-kwallet/Makefile
# used by sysutils/kf6-baloo/Makefile
# used by sysutils/kf6-kdbusaddons/Makefile
# used by sysutils/kf6-kfilemetadata/Makefile
# used by sysutils/kf6-solid/Makefile
# used by textproc/kf6-kcodecs/Makefile
# used by textproc/kf6-kcompletion/Makefile
# used by textproc/kf6-ktexttemplate/Makefile
# used by textproc/kf6-sonnet/Makefile
# used by textproc/kf6-syntax-highlighting/Makefile
# used by time/kf6-kcalendarcore/Makefile
# used by time/kf6-kholidays/Makefile
# used by www/kf6-syndication/Makefile
# used by x11/kf6-frameworkintegration/Makefile
# used by x11/kf6-kconfigwidgets/Makefile
# used by x11/kf6-kded/Makefile
# used by x11/kf6-kglobalaccel/Makefile
# used by x11/kf6-kguiaddons/Makefile
# used by x11/kf6-kirigami/Makefile
# used by x11/kf6-kitemviews/Makefile
# used by x11/kf6-kjobwidgets/Makefile
# used by x11/kf6-ktextwidgets/Makefile
# used by x11/kf6-kwidgetsaddons/Makefile
# used by x11/kf6-kwindowsystem/Makefile
# used by x11/kf6-kxmlgui/Makefile
# used by x11/kf6-qqc2-desktop-style/Makefile

KF6VER=		6.2.0
CATEGORIES+=	kde
MASTER_SITES=	${MASTER_SITE_KDE:=frameworks/${KF6VER:R}/}
EXTRACT_SUFX=	.tar.xz
PKGNAME?=	kf6-${DISTNAME}

TOOL_DEPENDS+= extra-cmake-modules>=${KF6VER}:../../devel/extra-cmake-modules
TOOLS_DEPENDS.cmake= cmake>=3.0:../../devel/cmake

CMAKE_ARGS+=	-DKF_IGNORE_PLATFORM_CHECK=true
.include "../../meta-pkgs/kde/Makefile.common"
