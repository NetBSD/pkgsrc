# $NetBSD: Makefile,v 1.1.1.1 2006/11/14 19:49:24 joerg Exp $
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

.include "../../x11/libXfont/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
