# $NetBSD: Makefile,v 1.9 1999/03/08 10:53:57 agc Exp $
#

DISTNAME=	sniffit.0.3.5
PKGNAME=	sniffit-0.3.5
CATEGORIES=	net security
MASTER_SITES=	http://reptile.rug.ac.be/~coder/sniffit/files/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://reptile.rug.ac.be/~coder/sniffit/sniffit.html

NOT_FOR_ARCHS=	alpha	# severe LP64 loss

do-build:
	cd ${WRKSRC} ; ./configure ; ${MAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sniffit ${PREFIX}/sbin/sniffit
	${INSTALL_MAN}     ${WRKSRC}/sniffit.5 ${PREFIX}/man/man5
	${INSTALL_MAN}     ${WRKSRC}/sniffit.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
