# $NetBSD: Makefile,v 1.9 2001/11/30 11:58:28 martti Exp $

DISTNAME=	db-3.3.11
PKGNAME=	db3-3.11.2
CATEGORIES=	databases
MASTER_SITES=	http://www.sleepycat.com/update/3.3.11/

MAINTAINER=	wrstuden@netbsd.org
HOMEPAGE=	http://www.sleepycat.com/
COMMENT=	Sleepycat Software's Berkeley DB version 3

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	patch.3.3.11.1 patch.3.3.11.2
PATCH_DIST_ARGS=-d ${WRKSRC}/.. --forward --quiet

USE_BUILDLINK_ONLY=	yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKDIR}/${DISTNAME}/dist/ltconfig
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../dist/configure

CONFIGURE_ARGS+=	--program-transform-name=s,db_,db3_,
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/db3
CONFIGURE_ARGS+=	--enable-cxx
CONFIGURE_ARGS+=	--enable-shared

WRKSRC=			${WRKDIR}/${DISTNAME}/build_unix

post-install:
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/share/doc/db3

.include "../../mk/bsd.pkg.mk"
