# $NetBSD: Makefile,v 1.5 2012/10/25 06:56:02 asau Exp $
#

DISTNAME=		jing-20090818
CATEGORIES=		textproc
MASTER_SITES=		http://jing-trang.googlecode.com/files/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.thaiopensource.com/relaxng/trang.html
COMMENT=		RELAX NG validator in Java

USE_TOOLS+=	pax

USE_JAVA=		run
USE_JAVA2=		1.4

do-build:
	${ECHO} "#!/bin/sh" > ${WRKSRC}/jing
	${ECHO} "${PKG_JAVA_HOME}/bin/java -jar ${PREFIX}/libexec/jing/jing.jar"' "$$@"' >> ${WRKSRC}/jing

INSTALLATION_DIRS=	bin libexec/jing/lib/xhtml/exclude \
			libexec/jing/lib/xhtml/modules share/doc/jing/doc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/jing ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/bin/* ${DESTDIR}${PREFIX}/libexec/jing
	${INSTALL_DATA} ${WRKSRC}/lib/*.* ${DESTDIR}${PREFIX}/libexec/jing/lib
	${INSTALL_DATA} ${WRKSRC}/lib/xhtml/*.* ${DESTDIR}${PREFIX}/libexec/jing/lib/xhtml
	${INSTALL_DATA} ${WRKSRC}/lib/xhtml/exclude/*.* ${DESTDIR}${PREFIX}/libexec/jing/lib/xhtml/exclude
	${INSTALL_DATA} ${WRKSRC}/lib/xhtml/modules/*.* ${DESTDIR}${PREFIX}/libexec/jing/lib/xhtml/modules
	${INSTALL_DATA} ${WRKSRC}/readme.html ${DESTDIR}${PREFIX}/share/doc/jing
	cd ${WRKSRC}/doc && pax -pp -rw * ${DESTDIR}${PREFIX}/share/doc/jing/doc

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
