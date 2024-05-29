# $NetBSD: Makefile,v 1.8 2024/05/29 16:34:16 adam Exp $

DISTNAME=	libkleo-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	security

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	KDE PIM cryptographic library
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	src/CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/libkleopatrarc \
		${PKG_SYSCONFDIR}/xdg/libkleopatrarc

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/kitemmodels/buildlink3.mk"
.include "../../security/qgpgme/buildlink3.mk"
.include "../../textproc/kpimtextedit/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
