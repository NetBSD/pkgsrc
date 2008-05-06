# $NetBSD: Makefile,v 1.1.1.1 2008/05/06 08:35:15 dillo Exp $
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
PKG_DESTDIR_SUPPORT=    user-destdir
INSTALLATION_DIRS=	share/doc/torrentzip

WRKSRC=	${WRKDIR}/trrntzip

pre-configure:
	cd ${WRKSRC} && sh autogen.sh

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/torrentzip

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
