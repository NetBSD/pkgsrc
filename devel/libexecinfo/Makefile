# $NetBSD: Makefile,v 1.6 2014/07/05 20:15:24 schmonz Exp $

DISTNAME=	libexecinfo-1.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_FREEBSD}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ober@NetBSD.org
HOMEPAGE=       http://www.freebsdsoftware.org/devel/libexecinfo.html
COMMENT=	BSD Licensed clone of backtrace facility found in GNU libc
LICENSE=	2-clause-bsd

CFLAGS.Linux+=	-D_GNU_SOURCE # Dl_info internals
CFLAGS.Linux+=	-Wno-unused-result # write(2) is declared specially
LIBS+=		-lm
LIBS.Linux+=	-ldl

USE_LIBTOOL=		yes

INSTALLATION_DIRS=	include lib

do-build:
	cd ${WRKSRC} && ${LIBTOOL} --mode=compile ${CC} ${CFLAGS} -c execinfo.c
	cd ${WRKSRC} && ${LIBTOOL} --mode=compile ${CC} ${CFLAGS} -c stacktraverse.c
	cd ${WRKSRC} && ${LIBTOOL} --mode=link ${CC} ${LDFLAGS} ${LIBS}	\
		-o libexecinfo.la execinfo.lo stacktraverse.lo		\
		-version-info 1:0:0 -rpath ${PREFIX}/lib

do-install:
	cd ${WRKSRC} && ${LIBTOOL} --mode=install ${INSTALL_LIB}	\
		-c libexecinfo.la ${DESTDIR}${PREFIX}/lib/libexecinfo.la
	cd ${WRKSRC} && ${INSTALL_DATA} execinfo.h ${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
