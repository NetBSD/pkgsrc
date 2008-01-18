# $NetBSD: Makefile,v 1.23 2008/01/18 05:08:54 tnn Exp $
#

.include "../../print/evince/Makefile.common"

PKGNAME=		${DISTNAME:S/evince/evince-nautilus/}
PKGREVISION=		1
COMMENT=		File properties plugin for evince files
PKG_OPTIONS_VAR=	PKG_OPTIONS.evince
PKG_SUPPORTED_OPTIONS=	dvi djvu
PKG_SUGGESTED_OPTIONS=	# none

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdvi)
CONFIGURE_ARGS+=	--enable-dvi
#BUILD_DIRS=		pdf dvi backend lib properties
# need shared libkpathsea
BUILDLINK_API_DEPENDS.teTeX-bin+=	teTeX-bin>=3.0nb13
.include "../../print/teTeX3-bin/buildlink3.mk"
.else
#BUILD_DIRS=		pdf backend lib properties
.endif

.if !empty(PKG_OPTIONS:Mdjvu)
CONFIGURE_ARGS+=	--enable-djvu
.include	"../../graphics/djvulibre-lib/buildlink3.mk"
.endif

INSTALL_DIRS=		properties

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
