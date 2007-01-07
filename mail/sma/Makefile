# $NetBSD: Makefile,v 1.11 2007/01/07 09:13:59 rillig Exp $

DISTNAME=       sma-1.4
CATEGORIES=	mail
MASTER_SITES=   http://www.klake.org/sma/dl/

MAINTAINER=	markus@core.de
HOMEPAGE=	http://www.klake.org/sma/
COMMENT=	Sendmail log analyser

WRKSRC=         ${WRKDIR}/${PKGNAME_NOREV}
NO_CONFIGURE=	yes

MAKE_FILE=	Makefile
BUILD_TARGET=	sma

.include "../../mk/bsd.prefs.mk"

.if empty(LOWER_OPSYS:Mirix5*)
CFLAGS+=	-DUSE_REGEXP
.endif
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

do-install:
	cd ${WRKSRC};						\
	${INSTALL_PROGRAM} sma ${PREFIX}/bin;			\
	${INSTALL_MAN} docs/sma.8 ${PREFIX}/${PKGMANDIR}/man8;		\
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sma;		\
	${INSTALL_DATA} README ${PREFIX}/share/doc/sma;	\
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/sma;	\
	${INSTALL_DATA} sma.conf ${PREFIX}/share/examples/sma

.include "../../mk/bsd.pkg.mk"
