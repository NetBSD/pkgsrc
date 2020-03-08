# $NetBSD: Makefile,v 1.15 2020/03/08 16:48:58 wiz Exp $

DISTNAME=	mcabber-1.1.0
PKGREVISION=	3
CATEGORIES=	chat
MASTER_SITES=	http://www.lilotux.net/~mikael/mcabber/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	degroote@NetBSD.org
HOMEPAGE=	https://www.lilotux.net/~mikael/mcabber/
COMMENT=	Jabber console client
LICENSE=	gnu-gpl-v2

CHECK_PORTABILITY_SKIP+=	contrib/events/eventcmd.pastebin

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake xgettext pkg-config
USE_NCURSES=	yes

INSTALLATION_DIRS+=	share/examples/mcabber
CONFIGURE_ARGS+=	--disable-hgcset

post-install:
	${INSTALL_DATA} ${WRKSRC}/mcabberrc.example \
			${DESTDIR}${PREFIX}/share/examples/mcabber
.include "options.mk"

.include "../../chat/loudmouth/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
