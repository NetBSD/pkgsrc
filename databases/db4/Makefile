# $NetBSD: Makefile,v 1.27 2004/11/17 06:04:43 jlam Exp $

DISTNAME=		db-4.2.52
PKGNAME=		${DISTNAME:S/db/db4/}
PKGREVISION=		6
CATEGORIES=		databases
MASTER_SITES=		http://www.sleepycat.com/update/snapshot/

PATCHFILES=		patch.4.2.52.1 patch.4.2.52.2
PATCH_SITES=		http://www.sleepycat.com/update/4.2.52/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.sleepycat.com/
COMMENT=		Berkeley DB version 4 from Sleepycat Software

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		${WRKSRC}/build_unix
BUILD_DIRS=		${CONFIGURE_DIRS}
CONFIGURE_SCRIPT=	../dist/configure

CONFIGURE_ARGS+=	--enable-cxx
CONFIGURE_ARGS+=	--enable-rpc
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-compat185
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/db4
CONFIGURE_ARGS+=	--program-transform-name=s,db_,db4_,

.include "../../mk/bsd.prefs.mk"

# NetBSD-sparc64-1.6*'s f77 makes configure failing and as f77 is not
# needed for this package the following does no harm on other platform.
CONFIGURE_ENV+=		F77=${FALSE}

.if defined(WITH_JAVA) && (${WITH_JAVA} == "yes")
CONFIGURE_ARGS+=	--enable-java
.  include "../../mk/java-vm.mk"
.endif

OPSYSVARS+=		LIBSO_LIBS
LIBSO_LIBS.SunOS+=	-lnsl
CONFIGURE_ENV+=		LIBSO_LIBS="${LIBSO_LIBS}"

.include "../../mk/pthread.buildlink3.mk"

post-install:
	${CHOWN} -R ${DOCOWN}:${DOCGRP} ${PREFIX}/share/doc/html/db4

.include "../../mk/bsd.pkg.mk"
