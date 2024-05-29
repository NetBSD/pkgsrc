# $NetBSD: Makefile,v 1.80 2024/05/29 16:31:29 adam Exp $

DISTNAME=	ekg-20200501
PKGREVISION=	18
CATEGORIES=	chat
MASTER_SITES=	http://ekg.chmurka.net/
MASTER_SITES+=	http://ekg.chmurka.net/archive/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://ekg.chmurka.net/
COMMENT=	Experimental Gadu-Gadu Client (Polish instant messaging system)
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-ui-ncurses
CONFIGURE_ARGS+=	--enable-ui-readline
CONFIGURE_ARGS+=	--with-curses=${BUILDLINK_PREFIX.curses}
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}
CONFIGURE_ARGS+=	--without-debug
PKGCONFIG_OVERRIDE=	lib/libgadu.pc.in

FAKE_NCURSES=		yes

.include "../../mk/pthread.buildlink3.mk"
.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} != "none")
CONFIGURE_ARGS+=	--with-pthread
.endif

# for backtrace
.if ${OPSYS} == "NetBSD" && exists(/usr/include/execinfo.h)
LIBS+=	-lexecinfo
.endif

.include "../../chat/libgadu/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
