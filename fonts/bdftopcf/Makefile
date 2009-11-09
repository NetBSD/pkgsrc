# $NetBSD: Makefile,v 1.5 2009/11/09 17:43:58 tnn Exp $
#

DISTNAME=		bdftopcf-1.0.2
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
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
