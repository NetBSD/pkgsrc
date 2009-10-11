# $NetBSD: Makefile,v 1.1.1.1 2009/10/11 09:36:56 wiz Exp $
#

DISTNAME=	epubcheck-1.0.3
CATEGORIES=	textproc
MASTER_SITES=	http://epubcheck.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://epubcheck.googlecode.com/
COMMENT=	Tool to validate IDPF Epub files
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
USE_JAVA=	run
INSTALLATION_DIRS=      bin libexec/epubcheck/lib share/doc/epubcheck

do-build:
	${ECHO} "#!/bin/sh" > ${WRKSRC}/epubcheck
	${ECHO} "${PKG_JAVA_HOME}/bin/java -jar ${PREFIX}/libexec/epubcheck/epubcheck-1.0.3.jar"' "$$@"' >> ${WRKSRC}/epubcheck

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/epubcheck ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/epubcheck-1.0.3.jar ${DESTDIR}${PREFIX}/libexec/epubcheck
# XXX: depend on saxon instead?
	${INSTALL_DATA} ${WRKSRC}/lib/saxon.jar ${DESTDIR}${PREFIX}/libexec/epubcheck/lib
	${INSTALL_DATA} ${WRKSRC}/COPYING.txt ${DESTDIR}${PREFIX}/share/doc/epubcheck
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${PREFIX}/share/doc/epubcheck
	${INSTALL_DATA} ${WRKSRC}/jing_license.txt ${DESTDIR}${PREFIX}/share/doc/epubcheck

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
