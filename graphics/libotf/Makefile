# $NetBSD: Makefile,v 1.11 2012/10/14 18:06:39 wiz Exp $
#

DISTNAME=	libotf-0.9.13
CATEGORIES=	graphics
MASTER_SITES=	http://download.savannah.gnu.org/releases/m17n/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	https://savannah.nongnu.org/projects/m17n
COMMENT=	Library for handling OpenType fonts (OTF)
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libotf.pc.in

.include "options.mk"

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
