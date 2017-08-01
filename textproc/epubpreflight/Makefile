# $NetBSD: Makefile,v 1.4 2017/08/01 17:00:42 wiz Exp $

DISTNAME=	epubpreflight-0.1.0
CATEGORIES=	textproc
MASTER_SITES=	http://epubcheck.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/IDPF/epubcheck
COMMENT=	Tool to validate IDPF EPUB files
LICENSE=	modified-bsd AND mit

WRKSRC=		${WRKDIR}
USE_JAVA=	run
INSTALLATION_DIRS=      bin libexec/epubpreflight/lib share/doc/epubpreflight

do-build:
	${ECHO} "#!/bin/sh" > ${WRKSRC}/epubpreflight
	${ECHO} "${PKG_JAVA_HOME}/bin/java -jar ${PREFIX}/libexec/epubpreflight/epubpreflight-0.1.0.jar"' "$$@"' >> ${WRKSRC}/epubpreflight

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/epubpreflight ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/epubpreflight-0.1.0.jar ${DESTDIR}${PREFIX}/libexec/epubpreflight
# XXX: depend on saxon instead?
	${INSTALL_DATA} ${WRKSRC}/lib/saxon.jar ${DESTDIR}${PREFIX}/libexec/epubpreflight/lib
	${INSTALL_DATA} ${WRKSRC}/COPYING.txt ${DESTDIR}${PREFIX}/share/doc/epubpreflight
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${PREFIX}/share/doc/epubpreflight
	${INSTALL_DATA} ${WRKSRC}/jing_license.txt ${DESTDIR}${PREFIX}/share/doc/epubpreflight

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
