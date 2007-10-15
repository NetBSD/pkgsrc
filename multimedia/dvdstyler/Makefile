# $NetBSD: Makefile,v 1.13 2007/10/15 06:07:18 wiz Exp $
#

DISTNAME=	DVDStyler-1.5b4
PKGNAME=	dvdstyler-1.5beta4
PKGREVISION=	7
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dvdstyler/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dvdstyler.de/
COMMENT=	Crossplatform DVD Authoring System

DEPENDS+=	dvdauthor>=0.6.10:../../multimedia/dvdauthor
DEPENDS+=	dvd+rw-tools-[0-9]*:../../sysutils/dvd+rw-tools
DEPENDS+=	mpgtx-[0-9]*:../../graphics/mpgtx

USE_DIRS+=		xdg-1.1
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config msgfmt
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--disable-kde
CONFIGURE_ARGS+=	--disable-gnome
CONFIGURE_ARGS+=	--disable-libgnomeui

.include "../../graphics/netpbm/buildlink3.mk"
.include "../../graphics/wxsvg/buildlink3.mk"
.include "../../multimedia/mjpegtools/buildlink3.mk"
.include "../../x11/wxGTK/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
