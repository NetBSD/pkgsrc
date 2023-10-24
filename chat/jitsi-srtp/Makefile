# $NetBSD: Makefile,v 1.2 2023/10/24 22:08:21 wiz Exp $

GITHUB_TAG=	88a9c387a8dc006a06dbe911ef1252423004927b
DISTNAME=	jitsi-srtp-1.1
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=jitsi/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/jitsi/jitsi-srtp/
COMMENT=	SRTP implementation for Jitsi
LICENSE=	apache-2.0

DISTINFO_FILE=	${.CURDIR}/../../chat/jitsi-srtp/distinfo
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	jitsi-srtp-java-deps-1.1.tar.gz
SITES.jitsi-srtp-java-deps-1.1.tar.gz= \
		ftp://ftp.NetBSD.org/pub/NetBSD/misc/khorben/

USE_TOOLS+=	pax:build

USE_CMAKE=		yes
CMAKE_ARGS+=		-DJAVA_INCLUDE_PATH2=${PKG_JAVA_HOME}/include/netbsd
CMAKE_ARGS+=		-DJITSI_SRTP_LIBSSL_VERSION=1.1
CMAKE_INSTALL_PREFIX=	${PREFIX}/lib

USE_JAVA2=	17

TOOL_DEPENDS+=	apache-maven-[0-9]*:../../devel/apache-maven

MAVEN_FLAGS+=	-Duser.home=${FAKEHOMEDIR}
MAVEN_FLAGS+=	-Dmaven.repo.local=${WRKDIR}/deps
MAVEN_FLAGS+=	--offline
MAVEN_FLAGS+=	-DskipTests
MAVEN_FLAGS+=	-Dassembly.skipAssembly=false
MVN=		${PKGSRC_SETENV} ${MAKE_ENV} mvn ${MAVEN_FLAGS}

.PHONY: create-deps-file
create-deps-file: build
	#XXX disable offline mode for maven before using this rule
	cd ${WRKSRC} && ${MVN} validate
	cd ${WRKDIR} && \
		${PAX} -wz -f jitsi-srtp-java-deps-${PKGVERSION_NOREV}.tar.gz deps

pre-build:
	cd ${WRKSRC} && ${MVN} compile

do-test:
	cd ${WRKSRC} && ${MVN} test

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
