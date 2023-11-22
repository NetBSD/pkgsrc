# $NetBSD: Makefile,v 1.8 2023/11/22 14:11:32 ryoon Exp $

DISTNAME=	openjdk-21.0.1_linux-x64_bin
PKGNAME=	${DISTNAME:S/_linux-x64_bin//:S/openjdk-/openjdk-bin-/}
CATEGORIES=	lang
MASTER_SITES=	https://download.java.net/java/GA/jdk21.0.1/415e3f918a1f4062a0074a2794853d0d/12/GPL/

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
EMUL_MODULES.linux=	locale x11

USE_TOOLS+=	pax
USE_LANGUAGES=	# none

JAVA_NAME=		openjdk-bin
JAVA_HOME=		${PREFIX}/java/${JAVA_NAME}
INSTALLATION_DIRS+=	${JAVA_HOME}

JAVA_WRAPPERS=	jar jarsigner java javac javadoc javap jcmd jconsole jdb \
		jdeprscan jdeps jfr jimage jinfo jlink jmap jmod jps \
		jrunscript jshell jstack jstat jstatd keytool rmid \
		rmiregistry serialver

do-install:
	cd ${WRKSRC} && pax -rwp ma . ${DESTDIR}${JAVA_HOME}

.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
