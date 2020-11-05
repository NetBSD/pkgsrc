# $NetBSD: Makefile,v 1.32 2020/11/05 09:07:00 ryoon Exp $

DISTNAME=	kemoticons-${KF5VER}
PKGREVISION=	2
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Support for emoticons and emoticons themes
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/src/providers/*/CMakeFiles/emoticonstheme_*_autogen.dir/AutogenInfo.json
SUBST_NOOP_OK.fix-moc=	yes
SUBST_SED.fix-moc=	-e 's;"${PREFIX}/include",;;g'

.include "../../meta-pkgs/kde/kf5.mk"

.include "../../archivers/karchive/buildlink3.mk"
.include "../../devel/kservice/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
