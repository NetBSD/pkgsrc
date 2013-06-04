# $NetBSD: Makefile,v 1.6 2013/06/04 22:16:48 tron Exp $
#

DISTNAME=	libass-0.10.1
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://libass.googlecode.com/files/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libass/
COMMENT=	Portable subtitle renderer for the ASS/SSA subtitle format
LICENSE=	isc

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libass.pc.in

BUILDLINK_API_DEPENDS.fribidi+=	fribidi>=0.19.0
.include "../../converters/fribidi/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../textproc/enca/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
