# $NetBSD: Makefile,v 1.7 2006/06/21 16:01:44 jlam Exp $
#

.include "../../print/evince/Makefile.common"

PKGNAME=		${DISTNAME:S/evince/evince-nautilus/}

COMMENT=		File properties plugin for evince files
PKG_OPTIONS_VAR=	PKG_OPTIONS.evince
PKG_SUPPORTED_OPTIONS=	dvi
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

INSTALL_DIRS=		properties

.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
