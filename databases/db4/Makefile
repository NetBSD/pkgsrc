# $NetBSD: Makefile,v 1.8 2003/12/07 00:51:07 epg Exp $

DISTNAME=		db-4.2.52
PKGNAME=		${DISTNAME:S/db/db4/}
WRKSRC=		${WRKDIR}/${DISTNAME}/build_unix
CATEGORIES=		databases
MASTER_SITES=	http://www.sleepycat.com/update/snapshot/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.sleepycat.com/
COMMENT=		Berkeley DB version 4 from Sleepycat Software

USE_BUILDLINK2=	YES
USE_GCC_SHLIB=	YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKDIR}/${DISTNAME}/build_unix/libtool
GNU_CONFIGURE=	YES
CONFIGURE_SCRIPT=	../dist/configure

CONFIGURE_ARGS+=	--enable-cxx
CONFIGURE_ARGS+=	--enable-rpc
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/db4
CONFIGURE_ARGS+=	--program-transform-name=s,db_,db4_,

.if defined(WITH_JAVA) && (${WITH_JAVA} == "YES")
CONFIGURE_ARGS+=	--enable-java
.  include "../../mk/java-vm.mk"
.endif

post-install:
	${CHOWN} -R ${DOCOWN}:${DOCGRP} ${PREFIX}/share/doc/db4

.include "../../mk/bsd.pkg.mk"
