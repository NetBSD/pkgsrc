# $NetBSD: Makefile,v 1.4 2002/12/31 15:44:28 jlam Exp $

DISTNAME=	db-4.0.14
PKGNAME=	db4-4.0.14
CATEGORIES=	databases
MASTER_SITES=	http://www.sleepycat.com/update/snapshot/

MAINTAINER=	dolemite@wuli.nu
HOMEPAGE=	http://www.sleepycat.com/
COMMENT=	Sleepycat Software's Berkeley DB version 4

USE_BUILDLINK2=		yes
USE_CXX=		yes
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

WRKSRC=			${WRKDIR}/${DISTNAME}/build_unix

post-install:
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/share/doc/db4

.include "../../mk/bsd.pkg.mk"
