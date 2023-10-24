# $NetBSD: Makefile,v 1.16 2023/10/24 22:10:21 wiz Exp $

DISTNAME=	lagrange-1.15.8
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	https://git.skyjake.fi/gemini/lagrange/releases/download/v${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gmi.skyjake.fi/lagrange/
COMMENT=	Desktop GUI client for browsing Gemini
LICENSE=	2-clause-bsd

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

USE_CC_FEATURES+=	c11

DEPENDS+=	zip-[0-9]*:../../archivers/zip

.include "options.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
