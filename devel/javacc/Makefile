# $NetBSD: Makefile,v 1.1.1.1 2006/05/11 03:50:02 minskim Exp $

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

INSTALLATION_DIRS+=	bin

do-install:
.for f in javacc jjdoc jjtree
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${PREFIX}/bin
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/bin/lib/javacc.jar ${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/javacc
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/javacc
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/javacc
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/javacc
	${CP} -R ${WRKSRC}/examples/* ${PREFIX}/share/examples/javacc
	${FIND} ${PREFIX}/share/examples/javacc -type d -print \
		| ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${PREFIX}/share/examples/javacc -type f -print \
		| ${XARGS} ${CHMOD} ${SHAREMODE}

.include "../../mk/bsd.pkg.mk"
