# $NetBSD: Makefile,v 1.4 2004/10/03 00:13:08 tv Exp $

DISTNAME=		ncmpc-0.11.0
PKGREVISION=	1
CATEGORIES=		audio
MASTER_SITES=		http://hem.bredband.net/kaw/ncmpc/files/ \
			http://mercury.chem.pitt.edu/~shank/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://hem.bredband.net/kaw/ncmpc/
COMMENT=		curses client for Music Player Daemon

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes

INCOMPAT_CURSES=	NetBSD-1.4*-* NetBSD-1.5*-*
INCOMPAT_CURSES+=	NetBSD-1.6.*-* NetBSD-1.6_*-*

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
