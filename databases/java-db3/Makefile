# $NetBSD: Makefile,v 1.32 2012/10/02 21:25:19 asau Exp $

DISTNAME=	db-3.3.11
PKGNAME=	java-db3-3.11.2
PKGREVISION=	1
CATEGORIES=	databases java
MASTER_SITES=	http://www.sleepycat.com/update/3.3.11/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.oracle.com/database/berkeley-db.html
COMMENT=	Java interface to Sleepycat Software's Berkeley DB version 3

PATCH_SITES=		${MASTER_SITES}
PATCHFILES=		patch.3.3.11.1 patch.3.3.11.2
PATCH_DIST_ARGS=	-d ${WRKSRC}/.. --forward --quiet

DISTINFO_FILE?=		${.CURDIR}/../db3/distinfo
PATCHDIR?=		${.CURDIR}/../db3/patches

JAVAC=			${PKG_JAVA_HOME}/bin/javac
JAR=			${PKG_JAVA_HOME}/bin/jar
JAVACABS=		${JAVAC}

WRKSRC=			${WRKDIR}/${DISTNAME}/build_unix
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
CONFIGURE_SCRIPT=	../dist/configure
CONFIG_SUB_OVERRIDE+=	../dist/config.sub
CONFIG_GUESS_OVERRIDE+=	../dist/config.guess

CONFIGURE_ARGS+=	--program-transform-name=s,db_,db3_,
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/db3
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-java
CONFIGURE_ENV+=		JAVAC=${JAVAC:Q}
CONFIGURE_ENV+=		JAVACABS=${JAVACABS:Q}
CONFIGURE_ENV+=		JAR=${JAR:Q}

CPPFLAGS+=		${BUILDLINK_CPPFLAGS.${PKG_JVM}}

BUILD_TARGET=		libdb3_java.la java
INSTALL_TARGET=		install_java

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# jdk 1.1.8 leads to segmentation faults when building the package.
USE_JAVA2=		yes
.endif

.include "../../databases/db3/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
