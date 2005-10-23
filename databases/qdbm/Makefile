# $NetBSD: Makefile,v 1.1.1.1 2005/10/23 19:01:56 minskim Exp $
#

DISTNAME=	qdbm-1.8.33
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qdbm/}

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://qdbm.sourceforge.net/
COMMENT=	Quick Database Manager - library of routines for managing a db

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-zlib
CONFIGURE_ARGS+=	--enable-iconv
PKGCONFIG_OVERRIDE=     qdbm.pc.in
TEST_TARGET=            check

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
CONFIGURE_ARGS+=        --without-pthread
.else
CONFIGURE_ARGS+=	--enable-pthread
CONFIGURE_ENV+=		CFLAGS=${PTHREAD_CFLAGS:Q}
CONFIGURE_ENV+=		LDFLAGS=${PTHREAD_LDFLAGS:Q}
SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	configure
SUBST_SED.pthread=	-e 's|-lpthread|${PTHREAD_LIBS}|'
.endif

.include "../../mk/bsd.pkg.mk"
