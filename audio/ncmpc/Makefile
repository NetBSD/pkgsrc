# $NetBSD: Makefile,v 1.2 2004/07/14 10:33:33 grant Exp $

DISTNAME=		ncmpc-0.11.0
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
INCOMPAT_CURSES+=	NetBSD-1.6.*-* NetBSD-1.6_*-* NetBSD-2*-*

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
