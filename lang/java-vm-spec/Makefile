# $NetBSD: Makefile,v 1.3 2003/03/29 12:41:26 jmmv Exp $

DISTNAME=		vmspec.2nded.html
PKGNAME=		java-vm-spec-2.0
WRKSRC=			${WRKDIR}/vmspec
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.javasoft.com/docs/specs/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://java.sun.com/docs/books/vmspec/index.html
COMMENT=		The Java(TM) Virtual Machine Specification (HTML)

NO_CONFIGURE=		# defined
NO_BUILD=		# defined

HTMLDIR=		${PREFIX}/share/doc/html/java-vm-spec

do-install:
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}/chars
	cd ${WRKSRC}; ${INSTALL_DATA} *.gif *.html ${HTMLDIR}
	cd ${WRKSRC}/chars; ${INSTALL_DATA} *.gif ${HTMLDIR}/chars

.include "../../mk/bsd.pkg.mk"
