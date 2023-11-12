# $NetBSD: Makefile,v 1.27 2023/11/12 13:22:07 wiz Exp $

DISTNAME=	libpuzzle-0.11
PKGREVISION=	23
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.pureftpd.org/pub/pure-ftpd/misc/libpuzzle/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://libpuzzle.pureftpd.org/project/libpuzzle
COMMENT=	Libpuzzle is designed to quickly find visually similar images
LICENSE=	isc

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

EGDIR=		${PREFIX}/share/doc/libpuzzle

INSTALLATION_DIRS=	${EGDIR} ${PKGMANDIR}/man3 ${PKGMANDIR}/man8

post-install:
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/THANKS ${DESTDIR}${EGDIR}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
