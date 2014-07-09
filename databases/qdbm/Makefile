# $NetBSD: Makefile,v 1.12 2014/07/09 14:31:32 asau Exp $
#

.include "Makefile.common"

CATEGORIES=	databases

COMMENT=	Quick Database Manager - library of routines for managing a db
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=	yes
MAKE_FILE=	LTmakefile
GNU_CONFIGURE=	yes
USE_TOOLS+=	pax

CONFIGURE_ARGS+=	--enable-zlib
CONFIGURE_ARGS+=	--enable-iconv
CONFIGURE_ARGS+=	--enable-bzip
CONFIGURE_ARGS+=	--enable-lzo
PKGCONFIG_OVERRIDE=	qdbm.pc.in
TEST_TARGET=		check

INSTALLATION_DIRS+=	bin include lib

post-install:
	cd ${WRKSRC}/doc;${PAX} -rwpp -s /.*~$$//g . ${DESTDIR}${PREFIX}/share/doc/qdbm

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
