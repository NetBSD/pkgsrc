# $NetBSD: Makefile,v 1.19 2019/04/25 20:56:31 markd Exp $

DISTNAME=	kemoticons-${KF5VER}
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Support for emoticons and emoticons themes
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/src/providers/xmpp/CMakeFiles/emoticonstheme_xmpp_autogen.dir/AutogenInfo.cmake
SUBST_FILES.fix-moc+=	_KDE_build/src/providers/kde/CMakeFiles/emoticonstheme_kde_autogen.dir/AutogenInfo.cmake
SUBST_FILES.fix-moc+=	_KDE_build/src/providers/adium/CMakeFiles/emoticonstheme_adium_autogen.dir/AutogenInfo.cmake
SUBST_FILES.fix-moc+=	_KDE_build/src/providers/pidgin/CMakeFiles/emoticonstheme_pidgin_autogen.dir/AutogenInfo.cmake
SUBST_SED.fix-moc=	-e 's,;${PREFIX}/include;,;,g'

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/kemoticons.categories \
		${PKG_SYSCONFDIR}/xdg/kemoticons.categories

.include "../../meta-pkgs/kde/kf5.mk"

.include "../../archivers/karchive/buildlink3.mk"
.include "../../devel/kservice/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
