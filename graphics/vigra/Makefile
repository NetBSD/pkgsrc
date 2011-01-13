# $NetBSD: Makefile,v 1.8 2011/01/13 13:36:10 wiz Exp $
#

DISTNAME=	vigra-1.7.0-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://hci.iwr.uni-heidelberg.de/vigra/

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://hci.iwr.uni-heidelberg.de/vigra/
COMMENT=	Computer vision library
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_CMAKE=		yes

INSTALL_MAKE_FLAGS+=	bindir=${DESTDIR}${PREFIX}/bin
INSTALL_MAKE_FLAGS+=	docdir=${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
INSTALL_MAKE_FLAGS+=	includedir=${DESTDIR}${PREFIX}/include
INSTALL_MAKE_FLAGS+=	libdir=${DESTDIR}${PREFIX}/lib

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
