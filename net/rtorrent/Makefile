# $NetBSD: Makefile,v 1.20 2007/04/20 13:37:58 tron Exp $

DISTNAME=	rtorrent-0.7.4
CATEGORIES=	net
MASTER_SITES=	${HOMEPAGE:=downloads/}

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://libtorrent.rakshasa.no/
COMMENT=	Ncurses based torrent client with support for sessions

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_NCURSES=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
GCC_REQD+=		3.3

.include "../../mk/bsd.prefs.mk"

.if !empty(OPSYS:M*BSD) || ${OPSYS} == "Darwin" || ${OPSYS} == "DragonFly"
MESSAGE_SRC=	${PKGDIR}/MESSAGE.BSD
.endif

.include "../../mk/compiler.mk"

# See http://libtorrent.rakshasa.no/ticket/96
.if !empty(CC_VERSION:Mgcc-4.*)
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
