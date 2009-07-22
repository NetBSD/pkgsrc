# $NetBSD: Makefile,v 1.2 2009/07/22 09:01:28 wiz Exp $

DISTNAME=	gnome-games-extra-data-2.26.0
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-games-extra-data/2.26/}
EXTRACT_SUFX=	.tar.bz2

PKG_DESTDIR_SUPPORT=	user-destdir

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME2 games collection - extra data files

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

DEPENDS+=	gnome-games>=2.24.0:../../games/gnome-games

.include "../../mk/bsd.pkg.mk"
