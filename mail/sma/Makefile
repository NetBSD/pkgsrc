# $NetBSD: Makefile,v 1.16 2014/01/23 11:58:39 tron Exp $

DISTNAME=	sma-1.4
CATEGORIES=	mail
MASTER_SITES=	http://www.klake.org/sma/dl/

MAINTAINER=	markus@marsrakete.de
HOMEPAGE=	http://www.klake.org/sma/
COMMENT=	Sendmail log analyser

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
NO_CONFIGURE=	yes

MAKE_FILE=	Makefile
BUILD_TARGET=	sma

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "IRIX"
CFLAGS+=	-DUSE_REGEXP
.endif
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

do-install:
	cd ${WRKSRC};							\
	${INSTALL_PROGRAM} sma ${DESTDIR}${PREFIX}/bin;			\
	${INSTALL_MAN} docs/sma.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8;\
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/sma;		\
	${INSTALL_DATA} README ${DESTDIR}${PREFIX}/share/doc/sma;	\
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/sma;	\
	${INSTALL_DATA} sma.conf ${DESTDIR}${PREFIX}/share/examples/sma

.include "../../mk/bsd.pkg.mk"
