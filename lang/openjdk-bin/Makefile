# $NetBSD: Makefile,v 1.2 2019/04/16 11:34:39 ryoon Exp $

DISTNAME=	openjdk-12_linux-x64_bin
PKGNAME=	${DISTNAME:S/_linux-x64_bin//:S/openjdk-/openjdk-bin-/}
CATEGORIES=	lang
MASTER_SITES=	https://download.java.net/java/GA/jdk12/GPL/

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

JAVA_WRAPPERS=	jar java javac javadoc javah javap jcmd jhat jps jstack \
		keytool orbd policytool rmid rmiregistry servertool tnameserv

do-install:
	cd ${WRKSRC} && pax -rwp ma . ${DESTDIR}${JAVA_HOME}

.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
