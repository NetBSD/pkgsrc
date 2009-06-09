# $NetBSD: Makefile,v 1.2 2009/06/09 08:31:20 imil Exp $
#

DISTNAME=	libpuzzle-0.11
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.pureftpd.org/pub/pure-ftpd/misc/libpuzzle/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://libpuzzle.pureftpd.org/project/libpuzzle
COMMENT=	Libpuzzle is designed to quickly find visually similar images

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

EGDIR=		${PREFIX}/share/doc/libpuzzle

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	${EGDIR} ${PKGMANDIR}/man3 ${PKGMANDIR}/man8

post-install:
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/THANKS ${DESTDIR}${EGDIR}

.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
