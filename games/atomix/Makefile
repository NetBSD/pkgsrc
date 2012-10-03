# $NetBSD: Makefile,v 1.26.2.1 2012/10/03 12:07:41 spz Exp $
#

DISTNAME=		atomix-2.14.0
PKGREVISION=		23
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/atomix/2.14/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://jens.triq.net/atomix.php
COMMENT=		Puzzle game

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
USE_TOOLS+=		intltool pkg-config gmake
LDFLAGS.DragonFly=	-lm

.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
