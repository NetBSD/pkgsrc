# $NetBSD: Makefile,v 1.12 2008/03/04 16:38:12 jlam Exp $

DISTNAME=		langspec-2.0.html
PKGNAME=		java-lang-spec-2.0
PKGREVISION=		2
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.javasoft.com/docs/specs/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://java.sun.com/docs/books/jls/index.html
COMMENT=		The Java(TM) Language Specification (HTML)

PKG_DESTDIR_SUPPORT=	user-destdir

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
