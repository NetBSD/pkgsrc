# $NetBSD: Makefile,v 1.17 2020/06/09 23:12:06 markd Exp $

DISTNAME=	kf5-${KF5VER}
CATEGORIES=	meta-pkgs x11 kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	https://www.kde.org/
COMMENT=	"meta-package" for the KDE Frameworks 5

KF5VER=		5.70.0

DEPENDS+=	attica-qt5>=${KF5VER}:../../misc/attica-qt5
DEPENDS+=	baloo5>=${KF5VER}:../../sysutils/baloo5
# bluez-qt
DEPENDS+=	breeze-icons>=${KF5VER}:../../graphics/breeze-icons
DEPENDS+=	frameworkintegration>=${KF5VER}:../../x11/frameworkintegration
DEPENDS+=	kactivities5>=${KF5VER}:../../x11/kactivities5
DEPENDS+=	kactivities-stats>=${KF5VER}:../../x11/kactivities-stats
DEPENDS+=	kapidox>=${KF5VER}:../../textproc/kapidox
DEPENDS+=	karchive>=${KF5VER}:../../archivers/karchive
DEPENDS+=	kauth>=${KF5VER}:../../security/kauth
DEPENDS+=	kbookmarks>=${KF5VER}:../../devel/kbookmarks
DEPENDS+=	kcalendarcore>=${KF5VER}:../../time/kcalendarcore
DEPENDS+=	kcmutils>=${KF5VER}:../../devel/kcmutils
DEPENDS+=	kcodecs>=${KF5VER}:../../textproc/kcodecs
DEPENDS+=	kcompletion>=${KF5VER}:../../textproc/kcompletion
DEPENDS+=	kconfig>=${KF5VER}:../../devel/kconfig
DEPENDS+=	kconfigwidgets>=${KF5VER}:../../x11/kconfigwidgets
DEPENDS+=	kcontacts>=${KF5VER}:../../misc/kcontacts
DEPENDS+=	kcoreaddons>=${KF5VER}:../../devel/kcoreaddons
DEPENDS+=	kcrash>=${KF5VER}:../../devel/kcrash
DEPENDS+=	kdbusaddons>=${KF5VER}:../../sysutils/kdbusaddons
DEPENDS+=	kdeclarative>=${KF5VER}:../../devel/kdeclarative
DEPENDS+=	kded>=${KF5VER}:../../x11/kded
DEPENDS+=	kdesignerplugin>=${KF5VER}:../../x11/kdesignerplugin
DEPENDS+=	kdesu>=${KF5VER}:../../security/kdesu
DEPENDS+=	kdnssd>=${KF5VER}:../../net/kdnssd
DEPENDS+=	kdoctools>=${KF5VER}:../../devel/kdoctools
DEPENDS+=	kemoticons>=${KF5VER}:../../misc/kemoticons
DEPENDS+=	kfilemetadata5>=${KF5VER}:../../sysutils/kfilemetadata5
DEPENDS+=	kglobalaccel>=${KF5VER}:../../x11/kglobalaccel
DEPENDS+=	kguiaddons>=${KF5VER}:../../x11/kguiaddons
DEPENDS+=	kholidays>=${KF5VER}:../../time/kholidays
DEPENDS+=	ki18n>=${KF5VER}:../../devel/ki18n
DEPENDS+=	kiconthemes>=${KF5VER}:../../graphics/kiconthemes
DEPENDS+=	kidletime>=${KF5VER}:../../devel/kidletime
DEPENDS+=	kimageformats>=${KF5VER}:../../graphics/kimageformats
DEPENDS+=	kinit>=${KF5VER}:../../x11/kinit
DEPENDS+=	kio>=${KF5VER}:../../devel/kio
DEPENDS+=	kirigami2>=${KF5VER}:../../x11/kirigami2
DEPENDS+=	kitemmodels>=${KF5VER}:../../devel/kitemmodels
DEPENDS+=	kitemviews>=${KF5VER}:../../x11/kitemviews
DEPENDS+=	kjobwidgets>=${KF5VER}:../../x11/kjobwidgets
DEPENDS+=	knewstuff>=${KF5VER}:../../net/knewstuff
DEPENDS+=	knotifications>=${KF5VER}:../../devel/knotifications
DEPENDS+=	knotifyconfig>=${KF5VER}:../../devel/knotifyconfig
DEPENDS+=	kpackage>=${KF5VER}:../../devel/kpackage
DEPENDS+=	kparts>=${KF5VER}:../../devel/kparts
DEPENDS+=	kpeople>=${KF5VER}:../../devel/kpeople
DEPENDS+=	kplotting>=${KF5VER}:../../graphics/kplotting
DEPENDS+=	kpty>=${KF5VER}:../../devel/kpty
DEPENDS+=	krunner>=${KF5VER}:../../devel/krunner
DEPENDS+=	kross>=${KF5VER}:../../devel/kross
DEPENDS+=	kservice>=${KF5VER}:../../devel/kservice
DEPENDS+=	ktexteditor>=${KF5VER}:../../devel/ktexteditor
DEPENDS+=	ktextwidgets>=${KF5VER}:../../x11/ktextwidgets
DEPENDS+=	kunitconversion>=${KF5VER}:../../misc/kunitconversion
DEPENDS+=	kwallet>=${KF5VER}:../../security/kwallet
DEPENDS+=	kwayland>=${KF5VER}:../../devel/kwayland
DEPENDS+=	kwidgetsaddons>=${KF5VER}:../../x11/kwidgetsaddons
DEPENDS+=	kwindowsystem>=${KF5VER}:../../x11/kwindowsystem
DEPENDS+=	kxmlgui>=${KF5VER}:../../x11/kxmlgui
DEPENDS+=	kxmlrpcclient>=${KF5VER}:../../net/kxmlrpcclient
# modemmanager-qt
# networkmanager-qt
DEPENDS+=	oxygen-icons>=${KF5VER}:../../graphics/oxygen-icons
DEPENDS+=	plasma-framework>=${KF5VER}:../../x11/plasma-framework
DEPENDS+=	prison>=${KF5VER}:../../graphics/prison
# purpose
DEPENDS+=	qqc2-desktop-style>=${KF5VER}:../../x11/qqc2-desktop-style
DEPENDS+=	solid>=${KF5VER}:../../sysutils/solid
DEPENDS+=	sonnet>=${KF5VER}:../../textproc/sonnet
DEPENDS+=	syntax-highlighting>=${KF5VER}:../../textproc/syntax-highlighting
DEPENDS+=	threadweaver>=${KF5VER}:../../devel/threadweaver

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
