# $NetBSD: Makefile,v 1.1.1.1 2006/11/14 19:58:25 joerg Exp $
#

DISTNAME=		mkcfm-1.0.1
CATEGORIES=		fonts
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		CID Font Summary generator

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

.include "../../x11/libFS/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXfont/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
