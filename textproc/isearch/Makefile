# $NetBSD: Makefile,v 1.4 2002/05/03 22:36:08 jtb Exp $

DISTNAME=		Isearch-1.47.01
PKGNAME=		isearch-1.47.01
CATEGORIES=		textproc databases
MASTER_SITES=		http://www.etymon.com/pub/Isearch/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.etymon.com/Isearch/
COMMENT=		Advanced text indexing and searching system

GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/isearch
	${INSTALL_DATA} ${WRKSRC}/TUTORIAL ${PREFIX}/share/doc/isearch
	${INSTALL_DATA} ${WRKSRC}/doc/DebugFirewall.doc ${PREFIX}/share/doc/isearch
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/isearch
	${INSTALL_DATA} ${WRKSRC}/html/*.html ${PREFIX}/share/doc/html/isearch/

.include "../../mk/bsd.pkg.mk"
