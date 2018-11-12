# $NetBSD: Makefile,v 1.39 2018/11/12 03:52:55 ryoon Exp $

DISTNAME=	kfilemetadata-${KF5VER}
PKGNAME=	${DISTNAME:S/-/5-/}
PKGREVISION=	5
CATEGORIES=	sysutils

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Library for extracting file metadata
LICENSE=	gnu-lgpl-v2 AND gnu-lgpl-v2.1 AND gnu-lgpl-v3

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	msgmerge pkg-config

DEPENDS+=	catdoc-[0-9]*:../../textproc/catdoc

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/kfilemetadata.categories \
		${PKG_SYSCONFDIR}/xdg/kfilemetadata.categories

.include "../../lang/python/tool.mk"
.include "../../archivers/karchive/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../devel/ki18n/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../multimedia/ffmpeg3/buildlink3.mk"
.include "../../print/poppler-qt5/buildlink3.mk"
.include "../../sysutils/attr/buildlink3.mk"
.include "../../textproc/ebook-tools/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
