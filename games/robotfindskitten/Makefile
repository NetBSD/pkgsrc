# $NetBSD: Makefile,v 1.5 2022/06/08 21:55:28 rillig Exp $
#

DISTNAME=	robotfindskitten-1.7320508.406
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://robotfindskitten.org/download/POSIX/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://robotfindskitten.org/
COMMENT=	Yet another zen simulation
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

INFO_FILES=	yes
FAKE_NCURSES=	yes

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
