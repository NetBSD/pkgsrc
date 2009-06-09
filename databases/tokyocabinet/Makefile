# $NetBSD: Makefile,v 1.30 2009/06/09 02:54:08 obache Exp $
#

DISTNAME=	tokyocabinet-1.4.24
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tokyocabinet/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://tokyocabinet.sourceforge.net/
COMMENT=	Modern implementation of DBM
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c99

PKGCONFIG_OVERRIDE+=	tokyocabinet.pc.in

CONFIGURE_ARGS+=	--enable-zlib
CONFIGURE_ARGS+=	--enable-bzip
CONFIGURE_ARGS+=	--enable-exlzma
CONFIGURE_ARGS+=	--enable-exlzo

TEST_TARGET=	check

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/lzmalib/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
PTHREAD_AUTO_VARS=	yes
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
CONFIGURE_ARGS+=	--disable-pthread
.else
CONFIGURE_ARGS+=	--enable-pthread
SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	configure
SUBST_SED.pthread=	-e 's|-lpthread|${PTHREAD_LIBS}|'
.endif
.include "../../mk/bsd.pkg.mk"
