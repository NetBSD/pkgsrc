# $NetBSD: Makefile,v 1.7 2006/09/09 02:41:56 obache Exp $
#

.include "Makefile.common"

CATEGORIES=	databases

COMMENT=	Quick Database Manager - library of routines for managing a db

USE_LIBTOOL=	yes
MAKE_FILE=	LTmakefile
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--enable-zlib
CONFIGURE_ARGS+=	--enable-iconv
CONFIGURE_ARGS+=	--enable-bzip
CONFIGURE_ARGS+=	--enable-lzo
PKGCONFIG_OVERRIDE=	qdbm.pc.in
TEST_TARGET=		check

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
CONFIGURE_ARGS+=	--without-pthread
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
