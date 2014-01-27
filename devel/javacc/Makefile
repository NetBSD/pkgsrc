# $NetBSD: Makefile,v 1.6 2014/01/27 18:41:11 wiz Exp $

DISTNAME=	javacc-5.0
CATEGORIES=	devel
MASTER_SITES=	http://java.net/projects/javacc/downloads/download/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://javacc.java.net/
COMMENT=	Java Compiler Compiler [tm]
LICENSE=	modified-bsd

NO_BUILD=	yes
USE_JAVA=	run
USE_JAVA2=	yes

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing classpath.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	bin/javacc bin/jjdoc bin/jjrun bin/jjtree
SUBST_VARS.paths=	PREFIX PKG_JAVA_HOME

.include "../../mk/java-vm.mk"

INSTALLATION_DIRS+=	bin share/examples/javacc

do-install:
.for f in javacc jjdoc jjrun jjtree
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
