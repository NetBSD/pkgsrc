# $NetBSD: Makefile,v 1.11 2016/07/24 20:35:20 rillig Exp $

DISTNAME=		vmspec.2nded.html
PKGNAME=		java-vm-spec-2.0
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.javasoft.com/docs/specs/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://docs.oracle.com/javase/specs/index.html
COMMENT=		The Java(TM) Virtual Machine Specification (HTML)

WRKSRC=			${WRKDIR}/vmspec
NO_CONFIGURE=		yes
NO_BUILD=		yes
AUTO_MKDIRS=		yes

HTMLDIR=		${PREFIX}/share/doc/java-vm-spec

do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} *.gif *.html ${DESTDIR}${HTMLDIR}
	cd ${WRKSRC}/chars && ${INSTALL_DATA} *.gif ${DESTDIR}${HTMLDIR}/chars

.include "../../mk/bsd.pkg.mk"
