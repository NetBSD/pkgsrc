# $NetBSD: Makefile,v 1.7 2003/06/10 09:54:41 wiz Exp $

DISTNAME=	db-4.1.25
PKGNAME=	db4-4.1.25
WRKSRC=		${WRKDIR}/${DISTNAME}/build_unix
CATEGORIES=	databases
MASTER_SITES=	http://www.sleepycat.com/update/snapshot/

PATCHFILES=		patch.4.1.25.1
PATCH_DIST_ARGS=	-d ${WRKDIR}/${DISTNAME} --forward --quiet -E ${PATCH_DIST_STRIP}
PATCH_SITES=		http://www.sleepycat.com/update/4.1.25/

MAINTAINER=	dolemite@wuli.nu
HOMEPAGE=	http://www.sleepycat.com/
COMMENT=	Sleepycat Software's Berkeley DB version 4

USE_BUILDLINK2=		yes
USE_GCC_SHLIB=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKDIR}/${DISTNAME}/build_unix/libtool
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../dist/configure

CONFIGURE_ARGS+=	--enable-rpc
CONFIGURE_ARGS+=        --program-transform-name=s,db_,db4_,
CONFIGURE_ARGS+=        --includedir=${PREFIX}/include/db4
CONFIGURE_ARGS+=	--enable-cxx
CONFIGURE_ARGS+=	--enable-shared

.if defined(WITH_JAVA) && (${WITH_JAVA} == "YES")
CONFIGURE_ARGS+=	--enable-java
.  include "../../mk/java-vm.mk"
.endif

post-install:
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/share/doc/db4

.include "../../mk/bsd.pkg.mk"
