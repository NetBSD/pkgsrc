# $NetBSD: Makefile,v 1.7 1998/10/15 19:51:07 agc Exp $
#

DISTNAME=	sniffit.0.3.5
PKGNAME=	sniffit-0.3.5
CATEGORIES=	net security
MASTER_SITES=	http://reptile.rug.ac.be/~coder/sniffit/files/

NOT_FOR_ARCHS=	alpha	# severe LP64 loss

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://reptile.rug.ac.be/~coder/sniffit/sniffit.html

do-build:
	cd ${WRKSRC} ; ./configure ; make

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sniffit ${PREFIX}/sbin/sniffit
	${INSTALL_MAN}     ${WRKSRC}/sniffit.5 ${PREFIX}/man/man5
	${INSTALL_MAN}     ${WRKSRC}/sniffit.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
