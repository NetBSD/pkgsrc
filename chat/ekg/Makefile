# $NetBSD: Makefile,v 1.21 2003/12/08 16:32:52 adam Exp $
#

DISTNAME=	ekg-1.4
CATEGORIES=	chat
MASTER_SITES=	http://dev.null.pl/ekg/ \
		http://dev.null.pl/ekg/stare/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://dev.null.pl/ekg/
COMMENT=	Experimental Gadu-Gadu Client (Polish instant messaging system)

USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_GNU_READLINE=	YES
USE_LIBTOOL=		YES
USE_NCURSES=		YES	# KEY_RESIZE, ncurses internals
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--enable-ui-ncurses
CONFIGURE_ARGS+=	--enable-ui-readline
CONFIGURE_ARGS+=	--with-curses=${BUILDLINK_PREFIX.ncurses}
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}
CONFIGURE_ARGS+=	--without-debug

.include "../../mk/pthread.buildlink2.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} != "none")
CONFIGURE_ARGS+=--with-pthread
.endif

.include "../../devel/ncurses/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
