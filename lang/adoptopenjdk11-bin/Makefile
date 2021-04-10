# $NetBSD: Makefile,v 1.7 2021/04/10 18:21:44 ryoon Exp $

PKGNAME=	adoptopenjdk11-bin-${GITHUB_RELEASE:S/jdk-//:S/+/./}
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdoptOpenJDK/}
GITHUB_PROJECT=	openjdk11-binaries
GITHUB_RELEASE=	jdk-11.0.10+9

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://adoptopenjdk.net/
COMMENT=	AdoptOpenJDK 11 Java Development Kit binary distribution
LICENSE=	gnu-gpl-v2 # with classpath exception

BUILD_DIRS=	# empty; instead of NO_BUILD=yes to create wrappers

EMUL_PLATFORMS=		linux-x86_64
EMUL_PLATFORMS+=	darwin-x86_64
EMUL_MODULES.linux=	compat locale x11

.include "../../mk/bsd.prefs.mk"

.if ${EMUL_OPSYS} == "linux"
DISTNAME=	OpenJDK11U-jdk_x64_linux_hotspot_11.0.10_9
WRKSRC=		${WRKDIR}/${GITHUB_RELEASE}
.elif ${EMUL_OPSYS} == "darwin"
DISTNAME=	OpenJDK11U-jdk_x64_mac_hotspot_11.0.10_9
WRKSRC=		${WRKDIR}/${GITHUB_RELEASE}/Contents/Home
.endif

# Contains pre-built binaries
CHECK_RELRO_SUPPORTED=	no
CHECK_SHLIBS_SUPPORTED=	no
CHECK_SSP_SUPPORTED=	no
CTF_SUPPORTED=		no

USE_TOOLS+=	pax
USE_LANGUAGES=	# none

JAVA_NAME=		adoptopenjdk11-bin
JAVA_HOME=		${PREFIX}/java/${JAVA_NAME}
INSTALLATION_DIRS+=	${JAVA_HOME}

JAVA_WRAPPERS=	jar jarsigner java javac javadoc javap jcmd jconsole jdb \
		jdeprscan jdeps jfr jimage jinfo jlink jmap jmod jps \
		jrunscript jshell jstack jstat jstatd keytool rmid \
		rmiregistry serialver

do-install:
	cd ${WRKSRC} && ${PAX} -rwp ma . ${DESTDIR}${JAVA_HOME}

.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
