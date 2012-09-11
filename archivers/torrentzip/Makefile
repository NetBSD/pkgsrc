# $NetBSD: Makefile,v 1.2 2012/09/11 19:47:01 asau Exp $
#

DISTNAME=	trrntzip_v02_src
PKGNAME=	torrentzip-0.2
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=trrntzip/}

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.sourceforge.net/trrntzip/
COMMENT=	Create identical zip archives from identical files

USE_TOOLS+=	aclocal autoconf automake autoheader
GNU_CONFIGURE=	yes
INSTALLATION_DIRS=	share/doc/torrentzip

WRKSRC=	${WRKDIR}/trrntzip

pre-configure:
	cd ${WRKSRC} && sh autogen.sh

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/torrentzip

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
