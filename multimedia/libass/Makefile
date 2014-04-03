# $NetBSD: Makefile,v 1.10 2014/04/03 08:21:52 wiz Exp $

DISTNAME=	libass-0.11.1
CATEGORIES=	multimedia
MASTER_SITES=	https://github.com/libass/libass/releases/download/0.11.1/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libass/
COMMENT=	Portable subtitle renderer for the ASS/SSA subtitle format
LICENSE=	isc

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libass.pc.in

LDFLAGS+=	${BUILDLINK_LDADD.iconv}

BUILDLINK_API_DEPENDS.fribidi+=	fribidi>=0.19.0
.include "../../converters/fribidi/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../textproc/enca/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
