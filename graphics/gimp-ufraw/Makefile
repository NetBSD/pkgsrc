# $NetBSD: Makefile,v 1.29 2006/07/22 04:46:16 rillig Exp $

DISTNAME=		ufraw-0.8.1
PKGNAME=		gimp-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ufraw/}

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://ufraw.sourceforge.net/
COMMENT=		GIMP plug-in for raw digicam import

GNU_CONFIGURE=		yes

USE_TOOLS+=		gmake pkg-config
USE_TOOLS+=		perl:run pod2man
USE_DIRS+=		xdg-1.1
USE_LANGUAGES=		c c++

# This package uses too much C99 code to be patched.
GCC_REQD+=		3.0
BUILDLINK_TRANSFORM+=	rm:-std=gnu99

PKG_OPTIONS_VAR=	PKG_OPTIONS.gimp-ufraw
PKG_SUPPORTED_OPTIONS=	exiv2 libexif
PKG_SUGGESTED_OPTIONS=	exiv2
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mexiv2)
CONFIGURE_ARGS+=	--with-exiv2 
.include "../../graphics/exiv2/buildlink3.mk"
.endif

# libexif has been reported to cause crashes with ufraw.  It is needed for Fuji RAF.
.if !empty(PKG_OPTIONS:Mlibexif)
CONFIGURE_ARGS+=	--with-libexif
.include "../../graphics/libexif/buildlink3.mk"
.endif

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/gimp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
