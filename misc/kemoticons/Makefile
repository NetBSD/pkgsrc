# $NetBSD: Makefile,v 1.24 2020/03/08 16:47:55 wiz Exp $

DISTNAME=	kemoticons-${KF5VER}
PKGREVISION=	1
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Support for emoticons and emoticons themes
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/src/providers/xmpp/CMakeFiles/emoticonstheme_xmpp_autogen.dir/AutogenInfo.json
SUBST_FILES.fix-moc+=	_KDE_build/src/providers/kde/CMakeFiles/emoticonstheme_kde_autogen.dir/AutogenInfo.json
SUBST_FILES.fix-moc+=	_KDE_build/src/providers/adium/CMakeFiles/emoticonstheme_adium_autogen.dir/AutogenInfo.json
SUBST_FILES.fix-moc+=	_KDE_build/src/providers/pidgin/CMakeFiles/emoticonstheme_pidgin_autogen.dir/AutogenInfo.json
SUBST_SED.fix-moc=	-e 's;"${PREFIX}/include",;;g'

.include "../../meta-pkgs/kde/kf5.mk"

.include "../../archivers/karchive/buildlink3.mk"
.include "../../devel/kservice/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
