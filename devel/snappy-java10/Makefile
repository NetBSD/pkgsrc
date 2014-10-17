# $NetBSD: Makefile,v 1.3 2014/10/17 16:45:46 joerg Exp $

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

MAKE_FLAGS+=	JAVA_HOME=${PKG_JAVA_HOME}

pre-build:
	${MKDIR} ${WRKSRC}/target
	${CP} -f ${DISTDIR}/${DIST_SUBDIR}/snappy-${SNAPPYVER}.tar.gz ${WRKSRC}/target

do-install:
	${INSTALL_DATA} ${WRKSRC}/target/snappy-java-${SNAPPYVER}.jar \
		${DESTDIR}${PREFIX}/lib/java/snappy-java

.include "../../mk/java-env.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
