# $NetBSD: Makefile,v 1.1.1.1 2000/10/15 03:00:07 jlam Exp $

DISTNAME=		vmspec.2nded.html
PKGNAME=		java-vm-spec-2.0
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.javasoft.com/docs/specs/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://java.sun.com/docs/books/vmspec/index.html

WRKSRC=			${WRKDIR}/vmspec
NO_CONFIGURE=		# defined
NO_BUILD=		# defined

HTMLDIR=		${PREFIX}/share/doc/html/java-vm-spec

do-install:
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}/chars
	cd ${WRKSRC}; ${INSTALL_DATA} *.gif *.html ${HTMLDIR}
	cd ${WRKSRC}/chars; ${INSTALL_DATA} *.gif ${HTMLDIR}/chars

.include "../../mk/bsd.pkg.mk"
