# $NetBSD: Makefile,v 1.4 1998/06/22 12:58:35 agc Exp $
#

DISTNAME=	sniffit.0.3.5
PKGNAME=	sniffit-0.3.5
CATEGORIES=	security
MASTER_SITES=	http://reptile.rug.ac.be/~coder/sniffit/files/

MAINTAINER=	packages@netbsd.org

do-build:
	cd ${WRKSRC} ; ./configure ; make

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sniffit ${PREFIX}/sbin/sniffit
	${INSTALL_MAN}     ${WRKSRC}/sniffit.5 ${PREFIX}/man/man5
	${INSTALL_MAN}     ${WRKSRC}/sniffit.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
