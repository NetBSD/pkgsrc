# $NetBSD: Makefile,v 1.8 2014/01/14 14:28:21 jperkin Exp $

DISTNAME=	libass-0.10.2
PKGREVISION=	1
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

LDFLAGS.SunOS+=	-liconv

BUILDLINK_API_DEPENDS.fribidi+=	fribidi>=0.19.0
.include "../../converters/fribidi/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../textproc/enca/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
