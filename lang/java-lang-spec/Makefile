# $NetBSD: Makefile,v 1.4 2003/03/29 12:41:26 jmmv Exp $

DISTNAME=		langspec-2.0.html
PKGNAME=		java-lang-spec-2.0
WRKSRC=			${WRKDIR}
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.javasoft.com/docs/specs/
EXTRACT_SUFX=		.zip

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://java.sun.com/docs/books/jls/index.html
COMMENT=		The Java(TM) Language Specification (HTML)

NO_CONFIGURE=		# defined
NO_BUILD=		# defined

HTMLDIR=		${PREFIX}/share/doc/html/java-lang-spec

do-install:
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}/chars
	cd ${WRKSRC}; ${INSTALL_DATA} *.gif *.html ${HTMLDIR}
	cd ${WRKSRC}/chars; ${INSTALL_DATA} *.gif ${HTMLDIR}/chars

.include "../../mk/bsd.pkg.mk"
