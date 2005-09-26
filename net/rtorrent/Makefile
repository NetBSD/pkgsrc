# $NetBSD: Makefile,v 1.2 2005/09/26 07:49:06 joerg Exp $

DISTNAME=	rtorrent-0.3.0
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

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/rtorrent
	${INSTALL_DATA} ${WRKSRC}/doc/rtorrent.rc \
		${PREFIX}/share/examples/rtorrent

.include "../../devel/ncurses/buildlink3.mk"
.include "../../net/libtorrent/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
