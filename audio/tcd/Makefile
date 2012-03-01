# $NetBSD: Makefile,v 1.8 2012/03/01 22:42:31 wiz Exp $
#

DISTNAME=		tcd-2.2.0
PKGREVISION=		3
CATEGORIES=		audio
MASTER_SITES=		http://download.savannah.gnu.org/releases/tcd/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.nongnu.org/tcd/
COMMENT=		Audio CD player using ncurses and SDL

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
INCOMPAT_CURSES+=	NetBSD-1.6*-*

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
