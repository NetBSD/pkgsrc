# $NetBSD: Makefile,v 1.7 2022/08/11 05:09:10 gutteridge Exp $

DISTNAME=	lagrange-1.6.5
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	https://git.skyjake.fi/gemini/lagrange/releases/download/v${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gmi.skyjake.fi/lagrange/
COMMENT=	Desktop GUI client for browsing Gemini
LICENSE=	2-clause-bsd

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

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
