# $NetBSD: Makefile,v 1.16 2023/05/19 09:33:26 wiz Exp $

DISTNAME=		dMagnetic_0.37
PKGNAME=		${DISTNAME:S/_/-/}
CATEGORIES=		games
MASTER_SITES=		https://www.dettus.net/dMagnetic/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dettus@dettus.net
HOMEPAGE=		https://www.dettus.net/dMagnetic/
COMMENT=		Magnetic Scrolls Interpreter
LICENSE=		2-clause-bsd

INSTALLATION_DIRS=	bin share/doc/dMagnetic share/examples/dMagnetic
INSTALL_MAKE_FLAGS+=	MYPREFIX=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	INSTALLMAN=${DESTDIR}${PREFIX}/${PKGMANDIR}

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/games/dMagnetic/dMagnetic.ini ${DESTDIR}${PREFIX}/share/examples/dMagnetic
	${MV} ${DESTDIR}${PREFIX}/share/games/dMagnetic/* ${DESTDIR}${PREFIX}/share/doc/dMagnetic

## The idea of this test is to check if the output is the expected one.
## for this, the sha256sum is being compared.
## dMagnetic has several output modes, each one of them is tested.
do-test:
	cd ${WRKSRC} && ${MAKE} SHA256_CMD=sha256 check

.include "../../mk/bsd.pkg.mk"
