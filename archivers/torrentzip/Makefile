# $NetBSD: Makefile,v 1.3 2012/12/12 10:44:06 wiz Exp $
#

DISTNAME=	trrntzip_v02_src
PKGNAME=	torrentzip-0.2
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=trrntzip/}

MAINTAINER=	pkgsrc-users@NetBSD.org
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
