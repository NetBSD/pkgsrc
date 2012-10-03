# $NetBSD: Makefile,v 1.48 2012/10/03 00:02:35 asau Exp $

DISTNAME=	ekg-1.7
PKGREVISION=	5
CATEGORIES=	chat
MASTER_SITES=	http://ekg.chmurka.net/ \
		http://ekg.chmurka.net/archive/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://ekg.chmurka.net/
COMMENT=	Experimental Gadu-Gadu Client (Polish instant messaging system)

USE_GNU_READLINE=	yes
USE_LIBTOOL=		yes
USE_NCURSES=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	lib/libgadu.pc.in
CONFIGURE_ARGS+=	--enable-ui-ncurses
CONFIGURE_ARGS+=	--enable-ui-readline
CONFIGURE_ARGS+=	--with-curses=${BUILDLINK_PREFIX.ncurses}
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}
CONFIGURE_ARGS+=	--without-debug

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} != "none")
CONFIGURE_ARGS+=	--with-pthread
.endif

# for backtrace
.if ${OPSYS} == "NetBSD" && exists(/usr/include/execinfo.h)
LIBS+=	-lexecinfo
.endif

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
