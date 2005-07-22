# $NetBSD: Makefile,v 1.1.1.1 2005/07/22 22:28:08 adam Exp $

DISTNAME=	rtorrent-0.3.0
CATEGORIES=	net
MASTER_SITES=	http://libtorrent.rakshasa.no/downloads/

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://libtorrent.rakshasa.no/
COMMENT=	Ncurses based torrent client with support for sessions

USE_LIBTOOL=		yes
USE_NCURSES=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/rtorrent
	${INSTALL_DATA} ${WRKSRC}/doc/rtorrent.rc \
		${PREFIX}/share/examples/rtorrent

.include "../../devel/ncurses/buildlink3.mk"
.include "../../net/libtorrent/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
