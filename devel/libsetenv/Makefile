# $NetBSD: Makefile,v 1.1.1.1 2007/08/03 21:30:59 tnn Exp $
#

DISTNAME=	libsetenv-0.1
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://www.pkgsrc.org/
COMMENT=	Library that provides setenv(3) and unsetenv(3) implementations

NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
USE_LIBTOOL=	yes

do-extract:
	cp -R ${FILESDIR} ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${LIBTOOL} --mode=compile ${COMPILE.c} libsetenv.c
	cd ${WRKSRC} && ${LIBTOOL} --mode=link ${LINK.c} -o libsetenv.la \
		libsetenv.lo -rpath ${PREFIX}/lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/libsetenv.h ${PREFIX}/include/
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/libsetenv.la ${PREFIX}/lib/

.include "../../mk/bsd.pkg.mk"
