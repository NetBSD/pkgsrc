# $NetBSD: Makefile,v 1.6 2004/04/24 22:46:10 jlam Exp $

DISTNAME=		vmspec.2nded.html
PKGNAME=		java-vm-spec-2.0
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.javasoft.com/docs/specs/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://java.sun.com/docs/books/vmspec/index.html
COMMENT=		The Java(TM) Virtual Machine Specification (HTML)

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
