# $NetBSD: Makefile,v 1.3 2012/10/06 11:54:41 asau Exp $

DISTNAME=	gnome-games-extra-data-2.26.0
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-games-extra-data/2.26/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME2 games collection - extra data files

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

DEPENDS+=	gnome-games>=2.24.0:../../games/gnome-games

.include "../../mk/bsd.pkg.mk"
