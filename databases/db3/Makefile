# $NetBSD: Makefile,v 1.36 2008/02/21 19:32:23 jlam Exp $

DISTNAME=	db-3.3.11
PKGNAME=	db3-3.11.2
PKGREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	http://download.oracle.com/berkeley-db/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.oracle.com/database/berkeley-db.html
COMMENT=	Sleepycat Software's Berkeley DB version 3

PATCH_SITES=	http://www.oracle.com/technology/products/berkeley-db/db/update/3.3.11/
PATCHFILES=	patch.3.3.11.1 patch.3.3.11.2
PATCH_DIST_ARGS=-d ${WRKSRC}/.. --forward --quiet -p0

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${DISTNAME}/build_unix
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

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "IRIX"
CONFIGURE_ENV+=		ac_cv_header_inttypes_h=no
.endif

post-install:
	${CHOWN} -R ${BINOWN}:${BINGRP} ${DESTDIR}${PREFIX}/share/doc/db3

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
