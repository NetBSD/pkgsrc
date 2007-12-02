# $NetBSD: Makefile,v 1.6 2007/12/02 13:04:10 wiz Exp $
#

DISTNAME=		focal
PKGNAME=		focal81-0
CATEGORIES=		lang
MASTER_SITES=		http://home.scarlet.be/~be042720/44/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://home.scarlet.be/~be042720/44/focal.htm
COMMENT=		Interpreted programming language


FOCALDOCDIR=	${PREFIX}/share/doc/focal

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/focal ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${FOCALDOCDIR}
	for i in focal.doc queens.foc sieve.foc; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${FOCALDOCDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
