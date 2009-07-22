# $NetBSD: Makefile,v 1.17 2009/07/22 09:01:38 wiz Exp $
#

DISTNAME=	DVDStyler-1.5.1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dvdstyler/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dvdstyler.de/
COMMENT=	Crossplatform DVD Authoring System

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	dvdauthor>=0.6.10:../../multimedia/dvdauthor
DEPENDS+=	dvd+rw-tools-[0-9]*:../../sysutils/dvd+rw-tools
DEPENDS+=	mpgtx-[0-9]*:../../graphics/mpgtx

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
.include "../../x11/wxGTK26/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
