# $NetBSD: Makefile,v 1.5 2006/03/04 21:29:53 jlam Exp $
#

DISTNAME=		focal
PKGNAME=		focal81-0
CATEGORIES=		lang
MASTER_SITES=		http://home.tiscali.be/be042720/44/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://home.tiscali.be/be042720/44/focal.htm
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
