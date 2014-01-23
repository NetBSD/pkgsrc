# $NetBSD: Makefile,v 1.17 2014/01/23 12:20:47 tron Exp $

DISTNAME=	sma-1.4
PKGREVISION=	1
CATEGORIES=	mail
#MASTER_SITES=	http://www.klake.org/sma/dl/

MAINTAINER=	markus@marsrakete.de
#HOMEPAGE=	http://www.klake.org/sma/
COMMENT=	Sendmail log analyser
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
NO_CONFIGURE=	yes

MAKE_FILE=	Makefile
BUILD_TARGET=	sma

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "IRIX"
CFLAGS+=	-DUSE_REGEXP
.endif
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8 share/doc/sma share/examples/sma

do-install:
	cd ${WRKSRC};							\
	${INSTALL_PROGRAM} sma ${DESTDIR}${PREFIX}/bin;			\
	${INSTALL_MAN} docs/sma.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8;\
	${INSTALL_DATA} README ${DESTDIR}${PREFIX}/share/doc/sma;	\
	${INSTALL_DATA} sma.conf ${DESTDIR}${PREFIX}/share/examples/sma

.include "../../mk/bsd.pkg.mk"
