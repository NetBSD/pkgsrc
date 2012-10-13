# $NetBSD: Makefile,v 1.10 2012/10/13 01:35:44 obache Exp $
#

DISTNAME=	libotf-0.9.12
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.m17n.org/libotf/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/m17n/
COMMENT=	Library for handling OpenType fonts (OTF)
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libotf.pc.in

.include "options.mk"

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
