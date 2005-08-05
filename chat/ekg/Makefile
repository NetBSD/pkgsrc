# $NetBSD: Makefile,v 1.32.2.1 2005/08/05 16:28:58 snj Exp $

DISTNAME=	ekg-1.6rc3
PKGNAME=	ekg-1.6
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	http://dev.null.pl/ekg/ \
		http://dev.null.pl/ekg/stare/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://dev.null.pl/ekg/
COMMENT=	Experimental Gadu-Gadu Client (Polish instant messaging system)

USE_GNU_READLINE=	yes
USE_LIBTOOL=		yes
USE_NCURSES=		yes
USE_TOOLS+=		gmake
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

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
