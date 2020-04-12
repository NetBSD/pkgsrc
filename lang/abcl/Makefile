# $NetBSD: Makefile,v 1.15 2020/04/12 19:39:11 joerg Exp $

DISTNAME=	abcl-src-1.5.0
PKGNAME=	${DISTNAME:C/-src//}
CATEGORIES=	lang
MASTER_SITES=	http://abcl.org/releases/${PKGVERSION_NOREV}/

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	https://abcl.org/
COMMENT=	Armed Bear Common Lisp

PKG_JVMS_ACCEPTED=	openjdk8 oracle-jdk8 openjdk7 sun-jdk7 jdk16 jdk15 kaffe

BUILD_DEPENDS=	apache-ant>=1.7.1:../../devel/apache-ant

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
