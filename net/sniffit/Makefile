# $NetBSD: Makefile,v 1.3 1998/04/15 10:38:40 agc Exp $
#

DISTNAME=	sniffit.0.3.5
PKGNAME=	sniffit-0.3.5
CATEGORIES=	security
MASTER_SITES=	http://reptile.rug.ac.be/~coder/sniffit/files/

MAINTAINER=	packages@netbsd.org

MAN5=		sniffit.5
MAN8=		sniffit.8

do-build:
	cd ${WRKSRC} ; ./configure ; make

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sniffit ${PREFIX}/sbin/sniffit
	${INSTALL_MAN}     ${WRKSRC}/sniffit.5 ${PREFIX}/man/man5
	${INSTALL_MAN}     ${WRKSRC}/sniffit.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
