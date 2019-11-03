# $NetBSD: Makefile,v 1.9 2019/11/03 10:39:30 rillig Exp $

DISTNAME=	snappy-java-${SNAPVER}${SNAPJVER}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=xerial/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/xerial/snappy-java/
COMMENT=	Snappy compressor/decompressor for Java
LICENSE=	apache-2.0

GITHUB_PROJECT=	snappy-java
SNAPVER=	1.0.5
SNAPJVER=	.4

DIST_SUBDIR=				${PKGBASE}
DISTFILES=				${DEFAULT_DISTFILES}
DISTFILES+=				snappy-java-deps-${SNAPVER}${SNAPJVER}.tar.gz
DISTFILES+=				snappy-${SNAPVER}.tar.gz
SITES.snappy-${SNAPVER}.tar.gz=		ftp://ftp.NetBSD.org/pub/NetBSD/misc/fhajny/
SITES.snappy-java-deps-${SNAPVER}${SNAPJVER}.tar.gz=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/fhajny/
EXTRACT_DIR.snappy-${SNAPVER}.tar.gz=	${WRKSRC}/target

TOOL_DEPENDS+=	apache-maven-[0-9]*:../../devel/apache-maven

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake
USE_JAVA=	yes
USE_JAVA2=	6

MAVEN_FLAGS+=	-Duser.home=${FAKEHOMEDIR}
MAVEN_FLAGS+=	-Dmaven.repo.local=${WRKDIR}/deps
MAVEN_FLAGS+=	--offline

MAKE_FLAGS+=	JAVA_HOME=${PKG_JAVA_HOME}
MAKE_FLAGS+=	MVN="mvn ${MAVEN_FLAGS}"
MAKE_JOBS_SAFE=	no

INSTALLATION_DIRS+=	lib/java/snappy-java

post-extract:
	${TOUCH} ${WRKSRC}/target/snappy-extracted.log
	${RM} -rf ${WRKSRC}/src/main/resources/org/xerial/snappy/native/*

do-install:
	${INSTALL_DATA} ${WRKSRC}/target/snappy-java-${SNAPVER}${SNAPJVER}.jar \
		${DESTDIR}${PREFIX}/lib/java/snappy-java/snappy-java.jar

.include "../../mk/java-env.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
