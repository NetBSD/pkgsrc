# $NetBSD: Makefile,v 1.38 2025/02/09 00:28:20 rillig Exp $

DISTNAME=	libass-0.17.3
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=libass/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libass/libass
COMMENT=	Portable subtitle renderer for the ASS/SSA subtitle format
LICENSE=	isc

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
GNU_CONFIGURE_ICONV=	no
CONFIGURE_ARGS+=	--disable-asm
PKGCONFIG_OVERRIDE+=	libass.pc.in

LDFLAGS+=	${BUILDLINK_LDADD.iconv}

.include "../../converters/fribidi/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/enca/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
