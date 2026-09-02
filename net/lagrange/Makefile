# $NetBSD: Makefile,v 1.35 2026/09/02 19:03:58 wiz Exp $

DISTNAME=	lagrange-1.20.8
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	https://git.skyjake.fi/gemini/lagrange/releases/download/v${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gmi.skyjake.fi/lagrange/
COMMENT=	Desktop GUI client for browsing Gemini
LICENSE=	2-clause-bsd

USE_TOOLS+=	pkg-config

USE_CC_FEATURES+=	c11

DEPENDS+=	zip-[0-9]*:../../archivers/zip

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
PLIST_SRC=	PLIST.Darwin

do-install:
	${RUN} mkdir -p ${DESTDIR}${PREFIX}/Applications
	${RUN} cp -R ${WRKSRC}/${CONFIGURE_DIR}/${CMAKE_BUILD_DIR}/Lagrange.app ${DESTDIR}${PREFIX}/Applications
.endif

.include "options.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
