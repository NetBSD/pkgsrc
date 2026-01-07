# $NetBSD: Makefile,v 1.17 2026/01/07 08:47:50 wiz Exp $

DISTNAME=	trojita-0.7
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=trojita/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://trojita.flaska.net/
COMMENT=	Fast Qt IMAP e-mail client
LICENSE=	gnu-gpl-v2

DEPENDS+=	ragel-[0-9]*:../../devel/ragel

USE_TOOLS+=	pkg-config

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++11

# Deprecation warnings burying the errors
CFLAGS+=	-Wno-deprecated -Wno-deprecated-declarations
CFLAGS+=	-Wno-misleading-indentation

CMAKE_CONFIGURE_ARGS+=	-Wno-dev
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_C_FLAGS=${CFLAGS:Q}

# Not a package
CMAKE_CONFIGURE_ARGS+=	-DWITH_MIMETIC=no
# Borken CMAKE build
CMAKE_CONFIGURE_ARGS+=	-DWITH_GPGMEPP=no
CMAKE_CONFIGURE_ARGS+=	-DWITH_CRYPTO_MESSAGES=no

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
#.include "../../security/gpgmepp/buildlink3.mk"
.include "../../security/qt5-qtkeychain/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../devel/cmake/build.mk"

.include "../../mk/bsd.pkg.mk"
