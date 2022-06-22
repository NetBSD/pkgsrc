# $NetBSD: Makefile,v 1.9 2022/06/22 10:25:38 nia Exp $

DISTNAME=	pljava-1.5.0
PKGNAME=	postgresql${PGSQL_VERSION}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=tada/}

GITHUB_PROJECT=			pljava
GITHUB_TAG=			V${PKGVERSION_NOREV:S/./_/g}
DISTFILES=			${DEFAULT_DISTFILES} ${DISTNAME}-deps.tar.gz
SITES.${DISTNAME}-deps.tar.gz=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/fhajny/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tada/pljava/
COMMENT=	Java Stored Procedures, Triggers, and Functions for PostgreSQL
LICENSE=	modified-bsd

DEPENDS+=	apache-maven-[0-9]*:../../devel/apache-maven
DEPENDS+=	postgresql${PGSQL_VERSION}-server>=0:../../databases/postgresql${PGSQL_VERSION}-server

USE_JAVA2=	7
USE_LANGUAGES=	c c++
TOOLS_BROKEN+=	perl

WRKSRC=		${WRKDIR}/${DISTNAME:S/./_/g}

PKG_JVMS_ACCEPTED=	openjdk8

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"
.include "../../mk/java-vm.mk"

.if !empty(PKG_JVM:Mopenjdk*)
LIBJVM=	${PKG_JAVA_HOME}/jre/lib/${MACHINE_ARCH:S/x86_64/amd64/:S/sparc64/sparcv9/:C/^e?arm.*$/arm/}/server/libjvm.${PG_LIB_EXT}
.else
LIBJVM=	${PKG_JAVA_HOME}/lib/${MACHINE_ARCH:S/x86_64/amd64/:S/sparc64/sparcv9/:C/^e?arm.*$/arm/}/server/libjvm.${PG_LIB_EXT}
.endif

SUBST_CLASSES+=		sun
SUBST_STAGE.sun=	pre-configure
SUBST_FILES.sun=	pljava-so/aol.solaris-gcc.properties
SUBST_MESSAGE.sun=	Fix SunOS build target
SUBST_SED.sun=		-e 's,/usr/sfw/include,${PGSQL_PREFIX}/include -I${PKG_JAVA_HOME}/include,'

SUBST_CLASSES+=		jvm
SUBST_MESSAGE.jvm=	Setting default libjvm path
SUBST_STAGE.jvm=	pre-configure
SUBST_FILES.jvm=	pljava-so/src/main/c/Backend.c
SUBST_VARS.jvm=		LIBJVM

MAVEN_FLAGS+=	--offline
MAVEN_FLAGS+=	-Plinkpglibs
MAVEN_FLAGS+=	-Pwnosign
MAVEN_FLAGS+=	-Duser.home=${FAKEHOMEDIR}
MAVEN_FLAGS+=	-Dmaven.repo.local=${WRKDIR}/deps
MAVEN_FLAGS+=	-Dnar.cores=${MAKE_JOBS:U1}
MAVEN_FLAGS+=	-Dpgsql.runpath=${PGSQL_PREFIX}/lib
MAVEN_FLAGS+=	-Dpgsql.runpathpfx=${COMPILER_RPATH_FLAG}
.if ${OPSYS} == "SunOS" && !empty(CC_VERSION:Mgcc*)
MAVEN_FLAGS+=	-Dnar.aolProperties=pljava-so/aol.solaris-gcc.properties
.elif ${OPSYS} == "NetBSD"
MAVEN_FLAGS+=	-Dnar.aolProperties=pljava-so/aol.netbsd.properties
.endif

INSTALL_FLAGS+=	-Dpgconfig.sharedir=${DESTDIR}${PREFIX}/share/postgresql
INSTALL_FLAGS+=	-Dpgconfig.pkglibdir=${DESTDIR}${PREFIX}/lib/postgresql

post-extract:
	${CP} ${PKGDIR}/files/aol.netbsd.properties ${WRKSRC}/pljava-so

do-build:
	${_ULIMIT_CMD} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} mvn ${MAVEN_FLAGS} install

do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} java ${INSTALL_FLAGS} -jar \
	pljava-packaging/target/pljava-pg${VER:!pg_config --version!:[2]:C/\.[0-9]+$//}-${MACHINE_ARCH:S/x86_64/amd64/}-${OPSYS}-gpp.jar

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
