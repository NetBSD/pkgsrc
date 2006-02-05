# $NetBSD: Makefile,v 1.7 2006/02/05 23:10:30 joerg Exp $

DISTNAME=	rtorrent-0.4.3
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://libtorrent.rakshasa.no/downloads/

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://libtorrent.rakshasa.no/
COMMENT=	Ncurses based torrent client with support for sessions

USE_LIBTOOL=		yes
USE_NCURSES=		yes
USE_TOOLS+=		gmake
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

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/rtorrent
	${INSTALL_DATA} ${WRKSRC}/doc/rtorrent.rc \
		${PREFIX}/share/examples/rtorrent

.include "../../devel/ncurses/buildlink3.mk"
.include "../../net/libtorrent/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
