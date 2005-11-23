# $NetBSD: Makefile,v 1.3 2005/11/23 06:20:36 minskim Exp $
#

.include "Makefile.common"

CATEGORIES=	databases

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
CFLAGS+=		${PTHREAD_CFLAGS}
LDFLAGS+=		${PTHREAD_LDFLAGS}
SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	configure
SUBST_SED.pthread=	-e 's|-lpthread|${PTHREAD_LIBS}|'
.endif

.include "../../mk/bsd.pkg.mk"
