# $NetBSD: Makefile,v 1.45 2012/10/31 11:19:55 asau Exp $

DISTNAME=	zlib-1.2.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libpng/} \
		http://www.gzip.org/zlib/
DISTFILES=	# empty

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.zlib.net/
COMMENT=	General purpose data compression library
LICENSE=	zlib

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes

CFLAGS+=		${CPPFLAGS}

INSTALLATION_DIRS=	include lib ${PKGMANDIR}/man3

do-extract:
	${CP} -r ${FILESDIR} ${WRKSRC}

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/libz.la ${DESTDIR}${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/zlib.3 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3
	${INSTALL_DATA} ${WRKSRC}/zconf.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/zlib.h ${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
