# $NetBSD: Makefile,v 1.5 2020/05/29 10:57:09 abs Exp $

DISTNAME=	openjdk-13.0.2_linux-x64_bin
PKGNAME=	${DISTNAME:S/_linux-x64_bin//:S/openjdk-/openjdk-bin-/}
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	https://download.java.net/java/GA/jdk13.0.2/d4173c853231432d94f001e99d882ca7/8/GPL/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://jdk.java.net/
COMMENT=	Official OpenJDK Java binary distribution
LICENSE=	gnu-gpl-v2 # with classpath exception

WRKSRC=		${WRKDIR}/jdk-${PKGVERSION_NOREV}
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

JAVA_NAME=		openjdk-bin
JAVA_HOME=		${PREFIX}/java/${JAVA_NAME}
INSTALLATION_DIRS+=	${JAVA_HOME}

JAVA_WRAPPERS=	jar java javac javadoc javah javap jcmd jhat jmap jps jstack \
		keytool orbd policytool rmid rmiregistry servertool tnameserv

do-install:
	cd ${WRKSRC} && pax -rwp ma . ${DESTDIR}${JAVA_HOME}

.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
