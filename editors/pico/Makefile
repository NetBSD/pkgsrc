# $NetBSD: Makefile,v 1.3 1998/06/27 03:29:04 tv Exp $
#

DISTNAME=	pine3.96
PKGNAME=	pico-2.9
WRKSRC=		${WRKDIR}/pine3.96
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/

MAINTAINER=	root@garbled.net

CONFLICTS=	pine-3.96

do-build:
	cd ${WRKSRC} && ./build neb

do-install:
	${INSTALL_DATA} ${WRKSRC}/pico/libpico.a ${PREFIX}/lib/libpico.a
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pico ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pilot ${PREFIX}/bin/
	${INSTALL_MAN}     ${WRKSRC}/doc/pico.1 ${PREFIX}/man/man1/
	${INSTALL_MAN}     ${WRKSRC}/doc/pilot.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
