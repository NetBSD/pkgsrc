# $NetBSD: Makefile,v 1.4 2012/10/31 11:17:07 asau Exp $

DISTNAME=	javacc-4.0
CATEGORIES=	devel
MASTER_SITES=	https://javacc.dev.java.net/files/documents/17/26776/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://javacc.dev.java.net/
COMMENT=	Java Compiler Compiler [tm]

NO_BUILD=	yes
USE_JAVA=	run
USE_JAVA2=	yes

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing classpath.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	bin/javacc bin/jjdoc bin/jjtree
SUBST_SED.paths=	-e 's,`dirname \$$0`/lib,${PREFIX}/lib/java,g'

.include "../../mk/java-vm.mk"

INSTALLATION_DIRS+=	bin share/examples/javacc

do-install:
.for f in javacc jjdoc jjtree
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${DESTDIR}${PREFIX}/bin
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/bin/lib/javacc.jar ${DESTDIR}${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/javacc
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/share/doc/javacc
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DESTDIR}${PREFIX}/share/doc/javacc
	${CP} -R ${WRKSRC}/examples/* ${DESTDIR}${PREFIX}/share/examples/javacc
	${FIND} ${DESTDIR}${PREFIX}/share/examples/javacc -type d -print \
		| ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${DESTDIR}${PREFIX}/share/examples/javacc -type f -print \
		| ${XARGS} ${CHMOD} ${SHAREMODE}

.include "../../mk/bsd.pkg.mk"
