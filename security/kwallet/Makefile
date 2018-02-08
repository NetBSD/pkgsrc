# $NetBSD: Makefile,v 1.37 2018/02/08 13:49:03 jperkin Exp $

DISTNAME=	kwallet-${KF5VER}
PKGREVISION=	1
CATEGORIES=	security

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Secure and unified container for user passwords
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

BUILD_DEPENDS+=	kdoctools>=${KF5VER}:../../devel/kdoctools

USE_TOOLS+=	msgmerge

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_DATAROOTDIR}/examples/kde-xdg:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/kwallet.categories \
		${PKG_SYSCONFDIR}/xdg/kwallet.categories

.include "../../lang/python/tool.mk"
.include "../../devel/knotifications/buildlink3.mk"
.include "../../devel/kservice/buildlink3.mk"
.include "../../graphics/kiconthemes/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
