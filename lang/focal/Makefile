# $NetBSD: Makefile,v 1.2 2004/04/28 05:06:28 snj Exp $
#

DISTNAME=		focal
PKGNAME=		focal81-0
CATEGORIES=		lang
MASTER_SITES=		http://home.tiscali.be/be042720/44/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://home.tiscali.be/be042720/44/focal.htm
COMMENT=		Interpreted programming language

USE_BUILDLINK3=		yes

FOCALDOCDIR=	${PREFIX}/share/doc/focal

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/focal ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${FOCALDOCDIR}
	for i in focal.doc queens.foc sieve.foc; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${FOCALDOCDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
