# $NetBSD: Makefile,v 1.10.2.1 2006/12/09 08:38:35 salo Exp $
#

.include "../../print/evince/Makefile.common"
PKGREVISION=		1

PKGNAME=		${DISTNAME:S/evince/evince-nautilus/}

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

.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
