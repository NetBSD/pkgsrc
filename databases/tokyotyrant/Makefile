# $NetBSD: Makefile,v 1.30 2012/10/02 21:25:55 asau Exp $
#

DISTNAME=	tokyotyrant-1.1.41
CATEGORIES=	databases net
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://fallabs.com/tokyotyrant/
COMMENT=	Network interface of Tokyo Cabinet
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	tokyotyrant.pc.in

TEST_TARGET=	check

.include "options.mk"

BUILDLINK_API_DEPENDS.tokyocabinet+=	tokyocabinet>=1.4.29
.include "../../databases/tokyocabinet/buildlink3.mk"
CONFIGURE_ARGS+=	--with-tc=${BUILDLINK_PREFIX.tokyocabinet}
.if !empty(PKG_BUILD_OPTIONS.tokyocabinet:Mbzip2)
CONFIGURE_ARGS+=	--with-bzip=${BUILDLINK_PREFIX.bzip2}
.endif
.if !empty(PKG_BUILD_OPTIONS.tokyocabinet:Mzlib)
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
.endif
PTHREAD_AUTO_VARS=	yes
PTHREAD_OPTS+=		require
.include "../../mk/pthread.buildlink3.mk"
SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	configure
SUBST_SED.pthread=	-e 's|-lpthread|${PTHREAD_LIBS}|'
.include "../../mk/bsd.pkg.mk"
