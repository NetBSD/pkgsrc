# $NetBSD: Makefile,v 1.9 1998/08/20 15:16:51 tsarna Exp $
#

DISTNAME=	pine4.02
PKGNAME=	pico-3.2
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.washington.edu/pine/

BUILD_DEPENDS=	${PREFIX}/bin/libtool:../../devel/libtool

CONFLICTS=	pico-2.9 pine-3.96 pico-3.0

do-build:
	cd ${WRKSRC} && ./build neb CC="${PREFIX}/bin/libtool ${CC}" PREFIX=${PREFIX}

do-install:
	${PREFIX}/bin/libtool --mode=install ${INSTALL_DATA} \
		${WRKSRC}/pico/libpico.la ${PREFIX}/lib/
	${PREFIX}/bin/libtool --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/pico/pico ${WRKSRC}/pico/pilot ${PREFIX}/bin/
	${INSTALL_MAN}     ${WRKSRC}/doc/pico.1 ${PREFIX}/man/man1/
	${INSTALL_MAN}     ${WRKSRC}/doc/pilot.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
