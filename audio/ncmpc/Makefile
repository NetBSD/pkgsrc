# $NetBSD: Makefile,v 1.1.1.1 2004/05/03 10:05:58 grant Exp $

DISTNAME=		ncmpc-0.10.1
CATEGORIES=		audio
MASTER_SITES=		http://mercury.chem.pitt.edu/~shank/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://musicpd.org/
COMMENT=		curses client for Music Player Daemon

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes

INCOMPAT_CURSES=	NetBSD-1.4*-* NetBSD-1.5*-*
INCOMPAT_CURSES+=	NetBSD-1.6.*-* NetBSD-1.6_*-*

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
