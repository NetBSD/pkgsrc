# $NetBSD: Makefile,v 1.3 2004/06/17 12:23:38 grant Exp $

DISTNAME=       sma-1.3.2
CATEGORIES=	mail
MASTER_SITES=   http://www.klake.org/sma/dl/

MAINTAINER=	markus@core.de
HOMEPAGE=	http://www.klake.org/sma/
COMMENT=	Sendmail log analyser

WRKSRC=         ${WRKDIR}/${PKGNAME_NOREV}
NO_CONFIGURE=	yes
USE_BUILDLINK3=	yes

MAKEFILE=	Makefile
ALL_TARGET=	sma

.include "../../mk/bsd.prefs.mk"

do-install:
	cd ${WRKSRC};						\
	${INSTALL_PROGRAM} sma ${PREFIX}/bin;			\
	${INSTALL_MAN} docs/sma.8 ${PREFIX}/man/man8;		\
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sma;		\
	${INSTALL_DATA} README ${PREFIX}/share/doc/sma;	\
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/sma;	\
	${INSTALL_DATA} sma.conf ${PREFIX}/share/examples/sma

.include "../../mk/bsd.pkg.mk"
