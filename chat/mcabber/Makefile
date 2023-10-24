# $NetBSD: Makefile,v 1.18 2023/10/24 22:08:22 wiz Exp $

DISTNAME=	mcabber-1.1.2
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	https://www.lilotux.net/~mikael/mcabber/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	degroote@NetBSD.org
HOMEPAGE=	https://www.lilotux.net/~mikael/mcabber/
COMMENT=	Small XMPP (Jabber) console client
LICENSE=	gnu-gpl-v2

CHECK_PORTABILITY_SKIP+=	contrib/events/eventcmd.pastebin

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake xgettext pkg-config
FAKE_NCURSES=	yes
USE_CURSES=	wide

INSTALLATION_DIRS+=	share/examples/mcabber
CONFIGURE_ARGS+=	--disable-hgcset

post-install:
	${INSTALL_DATA} ${WRKSRC}/mcabberrc.example \
			${DESTDIR}${PREFIX}/share/examples/mcabber
.include "options.mk"

.include "../../chat/loudmouth/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
