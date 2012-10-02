# $NetBSD: Makefile,v 1.10 2012/10/02 20:11:43 asau Exp $

DISTNAME=		vmspec.2nded.html
PKGNAME=		java-vm-spec-2.0
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.javasoft.com/docs/specs/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://java.sun.com/docs/books/vmspec/index.html
COMMENT=		The Java(TM) Virtual Machine Specification (HTML)

WRKSRC=			${WRKDIR}/vmspec
NO_CONFIGURE=		yes
NO_BUILD=		yes

HTMLDIR=		${PREFIX}/share/doc/html/java-vm-spec

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${HTMLDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${HTMLDIR}/chars
	cd ${WRKSRC}; ${INSTALL_DATA} *.gif *.html ${DESTDIR}${HTMLDIR}
	cd ${WRKSRC}/chars; ${INSTALL_DATA} *.gif ${DESTDIR}${HTMLDIR}/chars

.include "../../mk/bsd.pkg.mk"
