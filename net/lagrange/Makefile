# $NetBSD: Makefile,v 1.30 2026/03/02 12:09:00 pin Exp $

DISTNAME=	lagrange-1.19.4
CATEGORIES=	net
MASTER_SITES=	https://git.skyjake.fi/gemini/lagrange/releases/download/v${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gmi.skyjake.fi/lagrange/
COMMENT=	Desktop GUI client for browsing Gemini
LICENSE=	2-clause-bsd

USE_TOOLS+=	pkg-config

USE_CC_FEATURES+=	c11

DEPENDS+=	zip-[0-9]*:../../archivers/zip

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
