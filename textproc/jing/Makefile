# $NetBSD: Makefile,v 1.3 2009/07/07 21:34:26 joerg Exp $
#

DISTNAME=		jing-20030619
CATEGORIES=		textproc
MASTER_SITES=		http://www.thaiopensource.com/download/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.thaiopensource.com/relaxng/trang.html
COMMENT=		RELAX NG validator in Java

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pax

USE_JAVA=		run
USE_JAVA2=		1.4

do-build:
	${ECHO} "#!/bin/sh" > ${WRKSRC}/jing
	${ECHO} "${PKG_JAVA_HOME}/bin/java -jar ${PREFIX}/libexec/jing/jing.jar"' "$$@"' >> ${WRKSRC}/jing

INSTALLATION_DIRS=	bin libexec/jing/lib share/doc/jing/doc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/jing ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/bin/* ${DESTDIR}${PREFIX}/libexec/jing
	${INSTALL_DATA} ${WRKSRC}/lib/* ${DESTDIR}${PREFIX}/libexec/jing/lib
	${INSTALL_DATA} ${WRKSRC}/readme.html ${DESTDIR}${PREFIX}/share/doc/jing
	cd ${WRKSRC}/doc && pax -pp -rw * ${DESTDIR}${PREFIX}/share/doc/jing/doc

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
