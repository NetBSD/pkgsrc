# $NetBSD: Makefile,v 1.2 2008/10/09 13:01:00 obache Exp $
#

DISTNAME=	libotf-0.9.8
CATEGORIES=	graphics
MASTER_SITES=	http://www.m17n.org/libotf/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.m17n.org/libotf/
COMMENT=	Library for handling OpenType fonts (OTF)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libotf.pc.in

.include "options.mk"

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
