# $NetBSD: Makefile,v 1.1 2018/06/24 12:00:22 fhajny Exp $

DISTNAME=	pngquant-2.12.0-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	graphics
MASTER_SITES=	http://pngquant.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pngquant.org/
COMMENT=	Command-line utility for lossy compression of PNG images
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/pngquant-2.12.0

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c99
USE_TOOLS+=	gmake pkg-config

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-libimagequant=${BUILDLINK_PREFIX.libimagequant}
INSTALL_MAKE_FLAGS+=	MANPREFIX=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../graphics/libimagequant/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
