# $NetBSD: Makefile,v 1.5 2001/11/30 11:58:31 martti Exp $

DISTNAME=	db-3.3.11
PKGNAME=	java-db3-3.11.2
CATEGORIES=	databases
MASTER_SITES=	http://www.sleepycat.com/update/3.3.11/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.sleepycat.com/
COMMENT=	Java interface to Sleepycat Software's Berkeley DB version 3

PATCH_SITES=		${MASTER_SITES}
PATCHFILES=		patch.3.3.11.1 patch.3.3.11.2
PATCH_DIST_ARGS=	-d ${WRKSRC}/.. --forward --quiet

DISTINFO_FILE?=		${.CURDIR}/../db3/distinfo
PATCHDIR?=		${.CURDIR}/../db3/patches

USE_JAVA=		yes
JDK_BASE=		${JAVA_HOME}
JAVAC=			${JDK_BASE}/bin/javac
JAR=			${JDK_BASE}/bin/jar
JAVACABS=		${JAVAC}

USE_BUILDLINK_ONLY=	yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKDIR}/${DISTNAME}/dist/ltconfig
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../dist/configure

CONFIGURE_ARGS+=	--program-transform-name=s,db_,db3_,
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/db3
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-java
CONFIGURE_ENV+=		JAVAC="${JAVAC}"
CONFIGURE_ENV+=		JAVACABS="${JAVACABS}"
CONFIGURE_ENV+=		JAR="${JAR}"
ALL_TARGET=		libdb3_java.la java
INSTALL_TARGET=		install_java

WRKSRC=			${WRKDIR}/${DISTNAME}/build_unix

.include "../../databases/db3/buildlink.mk"
.include "../../mk/bsd.pkg.mk"

.if ${PKG_JVM} == "jdk"
CPPFLAGS+=		-I${JDK_BASE}/include/netbsd
.elif ${PKG_JVM} == "sun-jdk"
JDK_BASE=		${LOCALBASE}/java
CPPFLAGS+=		-I${JDK_BASE}/include/linux
.endif
