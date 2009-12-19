# $NetBSD: Makefile,v 1.26 2009/12/19 12:56:45 obache Exp $
#

DISTNAME=	tokyotyrant-1.1.33
PKGREVISION=	1
CATEGORIES=	databases net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tokyocabinet/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://1978th.net/tokyotyrant/
COMMENT=	Network interface of Tokyo Cabinet
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

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
.include "../../mk/pthread.buildlink3.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "none"
SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	configure
SUBST_SED.pthread=	-e 's|-lpthread|${PTHREAD_LIBS}|'
.endif
.include "../../mk/bsd.pkg.mk"
