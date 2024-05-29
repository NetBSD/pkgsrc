# $NetBSD: Makefile,v 1.9 2024/05/29 16:33:30 adam Exp $

DISTNAME=	akonadi-search-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/KDE_PIM
COMMENT=	Libraries and daemons to implement searching in Akonadi
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge pkg-config

SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/runner/CMakeFiles/*_autogen.dir/AutogenInfo.json
SUBST_NOOP_OK.fix-moc=	yes
SUBST_SED.fix-moc=	-e 's;"${PREFIX}/include",;;g'

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/kcmutils/buildlink3.mk"
.include "../../devel/krunner/buildlink3.mk"
.include "../../mail/akonadi-mime/buildlink3.mk"
.include "../../misc/kcontacts/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.include "../../time/kcalendarcore/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
