# $NetBSD: kf5.mk,v 1.8 2020/06/07 10:38:12 markd Exp $
# used by archivers/karchive/Makefile
# used by devel/kbookmarks/Makefile
# used by devel/kcmutils/Makefile
# used by devel/kconfig/Makefile
# used by devel/kcoreaddons/Makefile
# used by devel/kcrash/Makefile
# used by devel/kdeclarative/Makefile
# used by devel/kdoctools/Makefile
# used by devel/ki18n/Makefile
# used by devel/kidletime/Makefile
# used by devel/kio/Makefile
# used by devel/kitemmodels/Makefile
# used by devel/knotifications/Makefile
# used by devel/knotifyconfig/Makefile
# used by devel/kpackage/Makefile
# used by devel/kparts/Makefile
# used by devel/kpeople/Makefile
# used by devel/kpty/Makefile
# used by devel/kross/Makefile
# used by devel/krunner/Makefile
# used by devel/kservice/Makefile
# used by devel/ktexteditor/Makefile
# used by devel/kwayland/Makefile
# used by devel/threadweaver/Makefile
# used by graphics/breeze-icons/Makefile
# used by graphics/kiconthemes/Makefile
# used by graphics/kimageformats/Makefile
# used by graphics/kplotting/Makefile
# used by graphics/prison/Makefile
# used by misc/attica-qt5/Makefile
# used by misc/kcontacts/Makefile
# used by misc/kemoticons/Makefile
# used by misc/kunitconversion/Makefile
# used by net/kdnssd/Makefile
# used by net/knewstuff/Makefile
# used by net/kxmlrpcclient/Makefile
# used by security/kauth/Makefile
# used by security/kdesu/Makefile
# used by security/kwallet/Makefile
# used by sysutils/baloo5/Makefile
# used by sysutils/kdbusaddons/Makefile
# used by sysutils/kfilemetadata5/Makefile
# used by sysutils/solid/Makefile
# used by textproc/kapidox/Makefile
# used by textproc/kcodecs/Makefile
# used by textproc/kcompletion/Makefile
# used by textproc/sonnet/Makefile
# used by textproc/syntax-highlighting/Makefile
# used by time/kcalendarcore/Makefile
# used by time/kholidays/Makefile
# used by www/kdewebkit/Makefile
# used by www/kjs/Makefile
# used by www/kjsembed/Makefile
# used by www/khtml/Makefile
# used by x11/frameworkintegration/Makefile
# used by x11/kactivities-stats/Makefile
# used by x11/kactivities5/Makefile
# used by x11/kconfigwidgets/Makefile
# used by x11/kded/Makefile
# used by x11/kdelibs4support/Makefile
# used by x11/kdesignerplugin/Makefile
# used by x11/kglobalaccel/Makefile
# used by x11/kguiaddons/Makefile
# used by x11/kinit/Makefile
# used by x11/kirigami2/Makefile
# used by x11/kitemviews/Makefile
# used by x11/kjobwidgets/Makefile
# used by x11/ktextwidgets/Makefile
# used by x11/kwidgetsaddons/Makefile
# used by x11/kwindowsystem/Makefile
# used by x11/kxmlgui/Makefile
# used by x11/plasma-framework/Makefile
# used by x11/qqc2-desktop-style/Makefile

KF5VER=		5.70.0
CATEGORIES+=	kde
MASTER_SITES=	${MASTER_SITE_KDE:=frameworks/${KF5VER:R}/}
EXTRACT_SUFX=	.tar.xz

BUILD_DEPENDS+= extra-cmake-modules>=${KF5VER}:../../devel/extra-cmake-modules
TOOLS_DEPENDS.cmake= cmake>=3.0:../../devel/cmake

.include "../../meta-pkgs/kde/Makefile.common"
