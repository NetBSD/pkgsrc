# $NetBSD: Makefile,v 1.22 2023/11/12 13:22:07 wiz Exp $

DISTNAME=	libotf-0.9.16
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	https://download.savannah.gnu.org/releases/m17n/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://savannah.nongnu.org/projects/m17n
COMMENT=	Library for handling OpenType fonts (OTF)
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libotf.pc.in
CONFIGURE_ENV+=		HAVE_FREETYPE_CONFIG=yes # actually uses pkg-config now

.include "options.mk"

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
