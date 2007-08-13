# $NetBSD: Makefile,v 1.13 2007/08/13 05:38:02 rillig Exp $

DISTNAME=		ncmpc-0.11.1
PKGREVISION=		2
CATEGORIES=		audio
MASTER_SITES=		http://hem.bredband.net/kaw/ncmpc/files/ \
			http://mercury.chem.pitt.edu/~shank/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://hem.bredband.net/kaw/ncmpc/
COMMENT=		Curses client for Music Player Daemon

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config msgfmt

INCOMPAT_CURSES=	NetBSD-1.4*-* NetBSD-1.5*-*
INCOMPAT_CURSES+=	NetBSD-1.6.*-* NetBSD-1.6_*-*

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
