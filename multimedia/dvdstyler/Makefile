# $NetBSD: Makefile,v 1.7 2006/05/18 20:30:00 wiz Exp $
#

DISTNAME=	DVDStyler-1.5b4
PKGNAME=	dvdstyler-1.5beta4
PKGREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dvdstyler/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dvdstyler.sourceforge.net/
COMMENT=	Crossplatform DVD Authoring System

BROKEN_IN=	pkgsrc-2006Q1

DEPENDS+=	dvdauthor>=0.6.10:../../multimedia/dvdauthor
DEPENDS+=	dvd+rw-tools-[0-9]*:../../sysutils/dvd+rw-tools
DEPENDS+=	mpgtx-[0-9]*:../../graphics/mpgtx

USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		autoconf gmake pkg-config
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--disable-kde
CONFIGURE_ARGS+=	--disable-gnome
CONFIGURE_ARGS+=	--disable-libgnomeui

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../graphics/netpbm/buildlink3.mk"
.include "../../graphics/wxsvg/buildlink3.mk"
.include "../../multimedia/mjpegtools/buildlink3.mk"
.include "../../x11/wxGTK/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
