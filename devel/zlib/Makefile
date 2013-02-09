# $NetBSD: Makefile,v 1.46 2013/02/09 13:00:05 obache Exp $

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
LDFLAGS.Cygwin=		-no-undefined

INSTALLATION_DIRS=	include lib ${PKGMANDIR}/man3

do-extract:
	${CP} -r ${FILESDIR} ${WRKSRC}

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/libz.la ${DESTDIR}${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/zlib.3 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3
	${INSTALL_DATA} ${WRKSRC}/zconf.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/zlib.h ${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
