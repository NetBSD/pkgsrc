# $NetBSD: Makefile,v 1.1 1998/06/07 19:48:47 frueauf Exp $
#

DISTNAME=	pine3.96
PKGNAME=	pico-2.9
WRKSRC=		${WRKDIR}/pine3.96
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/

MAINTAINER=	root@garbled.net

CONFLICTS=	pine-3.96

MAN1= 		pico.1

do-build:
	cd ${WRKSRC} && ./build neb

do-install:
	${INSTALL_DATA} ${WRKSRC}/pico/libpico.a ${PREFIX}/lib/libpico.a
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pico ${PREFIX}/bin/pico
	${INSTALL_MAN}     ${WRKSRC}/doc/pico.1 ${PREFIX}/man/man1/pico.1

.include "../../mk/bsd.pkg.mk"
