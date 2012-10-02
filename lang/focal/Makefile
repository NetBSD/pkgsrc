# $NetBSD: Makefile,v 1.10 2012/10/02 20:11:39 asau Exp $
#

DISTNAME=		focal
PKGNAME=		focal81-0
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		http://home.scarlet.be/~be042720/44/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://home.scarlet.be/~be042720/44/focal.htm
COMMENT=		Interpreted programming language

FOCALDOCDIR=	${PREFIX}/share/doc/focal

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/focal ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${FOCALDOCDIR}
.for i in focal.doc queens.foc sieve.foc
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${FOCALDOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
