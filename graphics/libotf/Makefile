# $NetBSD: Makefile,v 1.8 2011/11/01 06:01:40 sbd Exp $
#

DISTNAME=	libotf-0.9.12
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.m17n.org/libotf/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.m17n.org/libotf/
COMMENT=	Library for handling OpenType fonts (OTF)
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libotf.pc.in

.include "options.mk"

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
