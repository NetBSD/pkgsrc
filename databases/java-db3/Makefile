# $NetBSD: Makefile,v 1.3 2001/09/17 18:13:53 jlam Exp $

DISTNAME=	db-3.2.9
PKGNAME=	java-db3-2.9
CATEGORIES=	databases
MASTER_SITES=	http://www.sleepycat.com/update/3.2.9/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.sleepycat.com/
COMMENT=	Java interface to Sleepycat Software's Berkeley DB version 3

DEPENDS+=	db3-2.9:../../databases/db3

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

.include "../../mk/bsd.pkg.mk"

.if ${PKG_JVM} == "jdk"
CPPFLAGS+=		-I${JDK_BASE}/include/netbsd
.elif ${PKG_JVM} == "sun-jdk"
JDK_BASE=		${LOCALBASE}/java
CPPFLAGS+=		-I${JDK_BASE}/include/linux
.endif
