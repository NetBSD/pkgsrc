# $NetBSD: Makefile,v 1.1.1.1 2012/02/17 16:57:25 jakllsch Exp $
#

DISTNAME=	robotfindskitten-1.7320508.406
CATEGORIES=	games
MASTER_SITES=	http://robotfindskitten.org/download/POSIX/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://robotfindskitten.org/
COMMENT=	Yet another zen simulation
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

INFO_FILES=	yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
