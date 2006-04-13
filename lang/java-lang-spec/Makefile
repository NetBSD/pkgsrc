# $NetBSD: Makefile,v 1.11 2006/04/13 00:47:19 rillig Exp $

DISTNAME=		langspec-2.0.html
PKGNAME=		java-lang-spec-2.0
PKGREVISION=		2
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.javasoft.com/docs/specs/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://java.sun.com/docs/books/jls/index.html
COMMENT=		The Java(TM) Language Specification (HTML)

WRKSRC=			${WRKDIR}
NO_CONFIGURE=		yes
NO_BUILD=		yes

HTMLDIR=		${PREFIX}/share/doc/java-lang-spec

do-install:
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}/chars
	cd ${WRKSRC}; ${INSTALL_DATA} *.gif *.html ${HTMLDIR}
	cd ${WRKSRC}/chars; ${INSTALL_DATA} *.gif ${HTMLDIR}/chars

.include "../../mk/bsd.pkg.mk"
