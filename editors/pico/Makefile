# $NetBSD: Makefile,v 1.13 1998/11/13 15:56:24 tv Exp $
#

DISTNAME=	pine4.05
PKGNAME=	pico-3.4
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.washington.edu/pine/

USE_LIBTOOL=	yes

CONFLICTS=	pico-2.9 pine-3.96 pico-3.0 pine-4.02 pico-3.2

do-build:
	cd ${WRKSRC} && ./build neb CC="${LIBTOOL} ${CC}" PREFIX=${PREFIX}

do-install:
	${LIBTOOL} --mode=install ${INSTALL_DATA} \
		${WRKSRC}/pico/libpico.la ${PREFIX}/lib/
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/pico/pico ${WRKSRC}/pico/pilot ${PREFIX}/bin/
	${INSTALL_MAN}     ${WRKSRC}/doc/pico.1 ${PREFIX}/man/man1/
	${INSTALL_MAN}     ${WRKSRC}/doc/pilot.1 ${PREFIX}/man/man1/
	${INSTALL_DATA_DIR} ${PREFIX}/include/pico
	cd ${WRKSRC}/pico && \
		${INSTALL_DATA} ebind.h edef.h efunc.h estruct.h headers.h \
			msmenu.h os.h pico.h resource.h \
			${PREFIX}/include/pico/

.include "../../mk/bsd.pkg.mk"
