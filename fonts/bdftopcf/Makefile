# $NetBSD: Makefile,v 1.2 2007/05/07 20:13:27 joerg Exp $
#

DISTNAME=		bdftopcf-1.0.0
CATEGORIES=		fonts
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		BDF to PCF font converter for X11

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

.include "../../x11/libXfont/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
