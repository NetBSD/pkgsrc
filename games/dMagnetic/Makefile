# $NetBSD: Makefile,v 1.11 2021/07/23 11:03:50 wiz Exp $

DISTNAME=		dMagnetic_0.32
PKGNAME=		${DISTNAME:S/_/-/}
CATEGORIES=		games
MASTER_SITES=		https://www.dettus.net/dMagnetic/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dettus@dettus.net
HOMEPAGE=		https://www.dettus.net/dMagnetic/
COMMENT=		Magnetic Scrolls Interpreter
LICENSE=		2-clause-bsd

INSTALLATION_DIRS=	bin share/doc/dMagnetic ${PKGMANDIR}/man5 ${PKGMANDIR}/man6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dMagnetic ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${PREFIX}/share/doc/dMagnetic
	${INSTALL_DATA} ${WRKSRC}/dMagnetic.ini ${DESTDIR}${PREFIX}/share/doc/dMagnetic
	${INSTALL_MAN} ${WRKSRC}/dMagneticini.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_MAN} ${WRKSRC}/dMagnetic.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6

## The idea of this test is to check if the output is the expected one.
## for this, the md5sum is being compared.
## dMagnetic has several output modes, each one of them is tested.
do-test:
	cd ${WRKSRC} && ${MAKE} SHA256_CMD=sha256 check

.include "../../mk/bsd.pkg.mk"
