# $NetBSD: Makefile,v 1.14 2007/09/19 23:18:53 wiz Exp $

DISTNAME=		teg-0.11.1
PKGREVISION=		10
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=teg/}

MAINTAINER=		wrzymski@gmail.com
HOMEPAGE=		http://teg.sourceforge.net/
COMMENT=		Round-based computer board game

USE_DIRS=		xdg-1.2 gnome2-1.5
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		intltool msgfmt pkg-config

GCONF2_SCHEMAS+=	teg.schemas

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../mk/bsd.pkg.mk"
