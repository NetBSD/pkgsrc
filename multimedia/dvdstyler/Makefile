# $NetBSD: Makefile,v 1.3 2006/01/31 02:57:18 xtraeme Exp $
#

DISTNAME=	DVDStyler-1.5b4
PKGNAME=	dvdstyler-1.5beta4
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dvdstyler/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://dvdstyler.sourceforge.net/
COMMENT=	Crossplatform DVD Authoring System

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
