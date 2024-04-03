# $NetBSD: Makefile,v 1.19 2024/04/03 14:15:41 ktnb Exp $

DISTNAME=	abcl-src-1.9.2
PKGNAME=	${DISTNAME:C/-src//}
CATEGORIES=	lang
MASTER_SITES=	http://abcl.org/releases/${PKGVERSION_NOREV}/

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	https://abcl.org/
COMMENT=	Armed Bear Common Lisp

PKG_JVMS_ACCEPTED=	openjdk17 openjdk11 openjdk8 oracle-jdk8 sun-jdk7 jdk16 jdk15 kaffe

TOOL_DEPENDS=	apache-ant>=1.7.1:../../devel/apache-ant

INSTALLATION_DIRS=	bin lib/abcl

do-build:
	${RUN}${_ULIMIT_CMD} cd ${WRKSRC} && \
	  ${PKGSRC_SETENV} ${MAKE_ENV} \
	    ant -nouserlib -Dabcl.runtime.jar.path=${PREFIX}/lib/abcl/abcl.jar

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/abcl ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/dist/abcl.jar ${DESTDIR}${PREFIX}/lib/abcl
	${INSTALL_DATA} ${WRKSRC}/dist/abcl-contrib.jar ${DESTDIR}${PREFIX}/lib/abcl

# TODO: requires network connectivity to fetch dependencies (e.g. JUnit)
do-test:
	${RUN}${_ULIMIT_CMD} cd ${WRKSRC} && \
	  ${PKGSRC_SETENV} ${MAKE_ENV} \
	    ant -nouserlib -Dabcl.runtime.jar.path=${PREFIX}/lib/abcl/abcl.jar abcl.test

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
