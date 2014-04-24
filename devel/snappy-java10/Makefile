# $NetBSD: Makefile,v 1.1 2014/04/24 16:15:43 ryoon Exp $

SNAPPYVER=	1.0.5
PKGNAME=	snappy-java10-${SNAPPYVER}
CATEGORIES=	devel

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://code.google.com/p/snappy-java/
COMMENT=	Snappy for Java, a fast compressor/decompressor library
LICENSE=	apache-2.0

DISTFILES+=	snappy-java-${SNAPPYVER}.tar.gz snappy-${SNAPPYVER}.tar.gz
SITES.snappy-${SNAPPYVER}.tar.gz=	https://snappy.googlecode.com/files/
SITES.snappy-java-${SNAPPYVER}.tar.gz=	http://snappy-java.googlecode.com/files/

TOOL_DEPENDS+=	apache-maven-[0-9]*:../../devel/apache-maven

DIST_SUBDIR=	snappy-java10

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV:S/snappy-java10/snappy-java/}

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake
USE_JAVA=	yes
USE_JAVA2=	6

INSTALLATION_DIRS+=	lib/java/snappy-java

.PHONY: do-create-jar pre-create-tar
pre-create-jar: do-extract do-patch
	${MKDIR} ${WRKSRC}/target
	${CP} -f ${DISTDIR}/snappy-${SNAPPYVER}.tar.gz ${WRKSRC}/target

do-create-jar: pre-create-jar
	cd ${WRKSRC} && \
	env ${MAKE_ENV} && \
		${MAKE_PROGRAM} JAVA_HOME=${PKG_JAVA_HOME} ${BUILD_MAKE_FLAGS} \
		-f ${MAKE_FILE} \
		${BUILD_TARGET}

do-build: do-create-jar

do-install:
	${INSTALL_DATA} ${WRKSRC}/target/snappy-java-${SNAPPYVER}.jar \
		${DESTDIR}${PREFIX}/lib/java/snappy-java

.include "../../mk/java-env.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
