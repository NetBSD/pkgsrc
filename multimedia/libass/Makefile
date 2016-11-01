# $NetBSD: Makefile,v 1.16 2016/11/01 20:15:28 maya Exp $

DISTNAME=	libass-0.13.4
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=libass/}
GITHUB_PROJECT=	libass
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libass/
COMMENT=	Portable subtitle renderer for the ASS/SSA subtitle format
LICENSE=	isc

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-asm
PKGCONFIG_OVERRIDE+=	libass.pc.in

LDFLAGS+=	${BUILDLINK_LDADD.iconv}

BUILDLINK_API_DEPENDS.fribidi+=	fribidi>=0.19.0
.include "../../converters/fribidi/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/enca/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
