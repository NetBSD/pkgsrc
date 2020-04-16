# $NetBSD: Makefile,v 1.3 2020/04/16 15:03:42 ryoon Exp $

DISTNAME=	OpenJDK11U-jdk_x64_linux_hotspot_11.0.7_10
PKGNAME=	${DISTNAME:S/OpenJDK11U-jdk_x64_linux_hotspot_/adoptopenjdk11-bin-/:S/_/./:tl}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdoptOpenJDK/}
GITHUB_PROJECT=	openjdk11-binaries
GITHUB_RELEASE=	jdk-11.0.7+10

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://adoptopenjdk.net/
COMMENT=	AdoptOpenJDK 11 Java Development Kit binary distribution
LICENSE=	gnu-gpl-v2 # with classpath exception

WRKSRC=		${WRKDIR}/${GITHUB_RELEASE}
BUILD_DIRS=	# empty; instead of NO_BUILD=yes to create wrappers

# Contains pre-built binaries
CHECK_RELRO_SUPPORTED=	no
CHECK_SHLIBS_SUPPORTED=	no
CHECK_SSP_SUPPORTED=	no
CTF_SUPPORTED=		no

EMUL_PLATFORMS=		linux-x86_64
EMUL_MODULES.linux=	compat locale x11

USE_TOOLS+=	pax
USE_LANGUAGES=	# none

JAVA_NAME=		adoptopenjdk11-bin
JAVA_HOME=		${PREFIX}/java/${JAVA_NAME}
INSTALLATION_DIRS+=	${JAVA_HOME}

JAVA_WRAPPERS=	jar java javac javadoc javah javap jcmd jhat jps jstack \
		keytool orbd policytool rmid rmiregistry servertool tnameserv

do-install:
	cd ${WRKSRC} && pax -rwp ma . ${DESTDIR}${JAVA_HOME}

.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
