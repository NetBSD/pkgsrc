# $NetBSD: Makefile,v 1.7 2008/03/04 16:38:12 jlam Exp $
#

DISTNAME=		focal
PKGNAME=		focal81-0
CATEGORIES=		lang
MASTER_SITES=		http://home.scarlet.be/~be042720/44/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://home.scarlet.be/~be042720/44/focal.htm
COMMENT=		Interpreted programming language

PKG_DESTDIR_SUPPORT=	user-destdir

FOCALDOCDIR=	${PREFIX}/share/doc/focal

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/focal ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${FOCALDOCDIR}
	for i in focal.doc queens.foc sieve.foc; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${DESTDIR}${FOCALDOCDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
