# $NetBSD: Makefile,v 1.14 2012/10/02 20:11:43 asau Exp $

DISTNAME=		langspec-3.0
PKGNAME=		java-lang-spec-3.0
CATEGORIES=		lang
MASTER_SITES=		http://java.sun.com/docs/books/jls/download/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://java.sun.com/docs/books/jls/index.html
COMMENT=		The Java(TM) Language Specification (HTML)

WRKSRC=			${WRKDIR}
NO_CONFIGURE=		yes
NO_BUILD=		yes

HTMLDIR=		${PREFIX}/share/doc/java-lang-spec

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${HTMLDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${HTMLDIR}/chars
	cd ${WRKSRC}; ${INSTALL_DATA} *.gif *.html ${DESTDIR}${HTMLDIR}
	cd ${WRKSRC}/chars; ${INSTALL_DATA} *.gif ${DESTDIR}${HTMLDIR}/chars

.include "../../mk/bsd.pkg.mk"
