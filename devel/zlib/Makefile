# $NetBSD: Makefile,v 1.42 2012/01/28 10:46:26 wiz Exp $

DISTNAME=	zlib-1.2.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libpng/} \
		http://www.gzip.org/zlib/
DISTFILES=	# empty

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.zlib.net/
COMMENT=	General purpose data compression library
LICENSE=	zlib

PKG_DESTDIR_SUPPORT=	user-destdir
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
