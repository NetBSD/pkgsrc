# $NetBSD: Makefile,v 1.17 2009/02/07 23:23:53 joerg Exp $

DISTNAME=		teg-0.11.1
PKGREVISION=		12
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=teg/}

MAINTAINER=		wrzymski@gmail.com
HOMEPAGE=		http://teg.sourceforge.net/
COMMENT=		Round-based computer board game

PKG_DESTDIR_SUPPORT=	user-destdir

USE_DIRS=		xdg-1.2 gnome2-1.5
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		intltool msgfmt pkg-config

GCONF_SCHEMAS+=	teg.schemas

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../mk/bsd.pkg.mk"
