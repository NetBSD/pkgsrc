# $NetBSD: Makefile,v 1.1.1.1 2001/02/06 22:09:27 jtb Exp $

DISTNAME=		Isearch-1.47d
PKGNAME=		isearch-1.47d
CATEGORIES=		textproc
MASTER_SITES=		http://www.etymon.com/pub/Isearch/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://www.etymon.com/Isearch/

GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/isearch
	${INSTALL_DATA} ${WRKSRC}/TUTORIAL ${PREFIX}/share/doc/isearch
	${INSTALL_DATA} ${WRKSRC}/doc/DebugFirewall.doc ${PREFIX}/share/doc/isearch
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/isearch
	@for f in ${WRKSRC}/html/*.html; do				   \
		i="${INSTALL_DATA} $$f ${PREFIX}/share/doc/html/isearch/"; \
		${ECHO} $$i; $$i;					   \
	done

.include "../../mk/bsd.pkg.mk"
