# $NetBSD: Makefile,v 1.28 2004/10/03 00:13:18 tv Exp $

DISTNAME=	db-3.3.11
PKGNAME=	db3-3.11.2
PKGREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	http://www.sleepycat.com/update/snapshot/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.sleepycat.com/
COMMENT=	Sleepycat Software's Berkeley DB version 3

PATCH_SITES=	http://www.sleepycat.com/update/3.3.11/
PATCHFILES=	patch.3.3.11.1 patch.3.3.11.2
PATCH_DIST_ARGS=-d ${WRKSRC}/.. --forward --quiet -p0

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${DISTNAME}/build_unix
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../dist/configure

CONFIG_SUB_OVERRIDE+=	../dist/config.sub
CONFIG_GUESS_OVERRIDE+=	../dist/config.guess

CONFIGURE_ARGS+=	--program-transform-name=s,db_,db3_,
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/db3
CONFIGURE_ARGS+=	--enable-cxx
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-compat185

post-install:
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/share/doc/html/db3

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
