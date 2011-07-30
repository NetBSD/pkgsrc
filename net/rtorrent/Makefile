# $NetBSD: Makefile,v 1.40 2011/07/30 17:06:33 tron Exp $

DISTNAME=	rtorrent-0.8.9
CATEGORIES=	net
MASTER_SITES=	${HOMEPAGE:=downloads/}

OWNER=		tron@NetBSD.org
HOMEPAGE=	http://libtorrent.rakshasa.no/
COMMENT=	Ncurses based torrent client with support for sessions
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_NCURSES=		chgat
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
GCC_REQD+=		3.3

.include "../../mk/pthread.buildlink3.mk"
LDFLAGS+=	${PTHREAD_LDFLAGS}

.include "options.mk"

.if !empty(OPSYS:M*BSD) || ${OPSYS} == "Darwin" || ${OPSYS} == "DragonFly"
MESSAGE_SRC=	${PKGDIR}/MESSAGE.BSD
.endif

# See http://libtorrent.rakshasa.no/ticket/77
.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-4.0.*)
CXXFLAGS+=	-fpermissive -fno-strength-reduce -fno-thread-jumps \
		-fno-inline -fforce-addr
.endif

INSTALLATION_DIRS=	share/examples/rtorrent

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/rtorrent.rc \
		${DESTDIR}${PREFIX}/share/examples/rtorrent

.include "../../devel/ncurses/buildlink3.mk"
.include "../../net/libtorrent/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
