# $NetBSD: Makefile,v 1.9 2011/01/29 16:29:03 adam Exp $

DISTNAME=	vigra-1.7.1-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	graphics
MASTER_SITES=	http://hci.iwr.uni-heidelberg.de/vigra/

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://hci.iwr.uni-heidelberg.de/vigra/
COMMENT=	Computer vision library
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

CMAKE_ARGS+=	-D DOCINSTALL:PATH=${DESTDIR}${PREFIX}/share/doc

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
