# $NetBSD: Makefile,v 1.2 2002/09/11 15:25:00 wiz Exp $

DISTNAME=	db-4.0.14
PKGNAME=	db4-4.0.14
CATEGORIES=	databases
MASTER_SITES=	http://www.sleepycat.com/update/snapshot/

MAINTAINER=	dolemite@wuli.nu
HOMEPAGE=	http://www.sleepycat.com/
COMMENT=	Sleepycat Software's Berkeley DB version 4

.if defined(WITH_JAVA) && (${WITH_JAVA} == "YES")
USE_JAVA=	YES
CONFIGURE_ARGS+=	--enable-java
.endif

USE_BUILDLINK_ONLY=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKDIR}/${DISTNAME}/build_unix/libtool
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../dist/configure

CONFIGURE_ARGS+=	--enable-rpc
CONFIGURE_ARGS+=        --program-transform-name=s,db_,db4_,
CONFIGURE_ARGS+=        --includedir=${PREFIX}/include/db4
CONFIGURE_ARGS+=	--enable-cxx
CONFIGURE_ARGS+=	--enable-shared

WRKSRC=			${WRKDIR}/${DISTNAME}/build_unix

post-install:
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/share/doc/db4

.include "../../mk/bsd.pkg.mk"
