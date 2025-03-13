# $NetBSD: Makefile,v 1.10 2025/03/13 19:16:15 wiz Exp $

DISTNAME=	epubcheck-5.2.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=w3c/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/w3c/epubcheck
COMMENT=	Conformance checker for EPUB publications
LICENSE=	apache-2.0 AND modified-bsd AND mit AND mpl-2.0 AND w3c AND unicode-v3

USE_JAVA=		run
INSTALLATION_DIRS=	bin libexec/epubcheck/lib share/doc/epubcheck

do-build:
	${ECHO} "#!/bin/sh" > ${WRKSRC}/epubcheck
	${ECHO} "${PKG_JAVA_HOME}/bin/java -jar ${PREFIX}/libexec/epubcheck/epubcheck.jar"' "$$@"' >> ${WRKSRC}/epubcheck

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/epubcheck ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/epubcheck.jar ${DESTDIR}${PREFIX}/libexec/epubcheck
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${DESTDIR}${PREFIX}/libexec/epubcheck/lib
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${PREFIX}/share/doc/epubcheck

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
