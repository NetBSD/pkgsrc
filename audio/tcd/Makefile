# $NetBSD: Makefile,v 1.4 2006/06/12 16:28:05 wiz Exp $
#

DISTNAME=		tcd-2.2.0
PKGREVISION=		3
CATEGORIES=		audio
MASTER_SITES=		http://savannah.gnu.org/download/tcd/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		roland.illig@gmx.de
HOMEPAGE=		http://savannah.gnu.org/download/tcd/
COMMENT=		Audio CD player using ncurses and SDL

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
INCOMPAT_CURSES+=	NetBSD-1.6*-*

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
