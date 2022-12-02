# $NetBSD: Makefile,v 1.1 2022/12/02 10:48:38 jperkin Exp $

PKGNAME=	oracle-jdk17-17.0.5
CATEGORIES=	lang java
MASTER_SITES=	https://download.oracle.com/java/17/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.oracle.com/java/
COMMENT=	Oracle Java Platform, Standard Edition Development Kit
LICENSE=	oracle-no-fee

USE_TOOLS+=	pax

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_PLATFORM:MLinux-*-aarch64} || make(distinfo) || make(makesum) || make(mdi)
DISTFILES+=	jdk-${PKGVERSION_NOREV}_linux-aarch64_bin.tar.gz
.endif
.if ${MACHINE_PLATFORM:MLinux-*-x86_64} || make(distinfo) || make(makesum) || make(mdi)
DISTFILES+=	jdk-${PKGVERSION_NOREV}_linux-x64_bin.tar.gz
.endif
.if ${MACHINE_PLATFORM:MDarwin-*-aarch64} || make(distinfo) || make(makesum) || make(mdi)
DISTFILES+=	jdk-${PKGVERSION_NOREV}_macos-aarch64_bin.tar.gz
.endif
.if ${MACHINE_PLATFORM:MDarwin-*-x86_64} || make(distinfo) || make(makesum) || make(mdi)
DISTFILES+=	jdk-${PKGVERSION_NOREV}_macos-x64_bin.tar.gz
.endif

.if !defined(DISTFILES)
NOT_FOR_PLATFORM+=	${MACHINE_PLATFORM}
.endif

.if ${OPSYS} == "Darwin"
WRKSRC=		${WRKDIR}/jdk-${PKGVERSION_NOREV}.jdk/Contents/Home
.else
WRKSRC=		${WRKDIR}/jdk-${PKGVERSION_NOREV}
.endif

# Contains pre-built binaries
CHECK_RELRO_SUPPORTED=	no
CHECK_SHLIBS_SUPPORTED=	no
CHECK_SSP_SUPPORTED=	no
CTF_SUPPORTED=		no
MKPIE_SUPPORTED=	no

BUILD_DIRS=		# empty

JAVA_HOME=		${PREFIX}/java/oracle-jdk17
JAVA_NAME=		oracle-jdk17
JAVA_UNLIMIT=		datasize
JAVA_WRAPPERS=		jar jarsigner java javac javadoc javap jcmd jconsole
JAVA_WRAPPERS+=		jdb jdeprscan jdeps jfr jhsdb jimage jinfo jlink jmap
JAVA_WRAPPERS+=		jmod jpackage jps jrunscript jshell jstack jstat jstatd
JAVA_WRAPPERS+=		keytool rmiregistry serialver

PRINT_PLIST_AWK+=	/^java\/.*\/man\// { sub("\\.gz$$", ""); }

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${JAVA_HOME}
	cd ${WRKSRC} && pax -rwp ma . ${DESTDIR}${JAVA_HOME}

.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
