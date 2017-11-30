# $NetBSD: Makefile,v 1.8 2017/11/30 16:45:05 adam Exp $

DISTNAME=	kemoticons-${KF5VER}
PKGREVISION=	6
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Support for emoticons and emoticons themes
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/src/providers/xmpp/CMakeFiles/emoticonstheme_xmpp_automoc.dir/AutogenInfo.cmake
SUBST_FILES.fix-moc+=	_KDE_build/src/providers/kde/CMakeFiles/emoticonstheme_kde_automoc.dir/AutogenInfo.cmake
SUBST_FILES.fix-moc+=	_KDE_build/src/providers/adium/CMakeFiles/emoticonstheme_adium_automoc.dir/AutogenInfo.cmake
SUBST_FILES.fix-moc+=	_KDE_build/src/providers/pidgin/CMakeFiles/emoticonstheme_pidgin_automoc.dir/AutogenInfo.cmake
SUBST_SED.fix-moc=	-e 's,;${PREFIX}/include;,;,g'

.include "../../meta-pkgs/kf5/Makefile.common"

.include "../../archivers/karchive/buildlink3.mk"
.include "../../devel/kservice/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
