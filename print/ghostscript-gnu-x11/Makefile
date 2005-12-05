# $NetBSD: Makefile,v 1.7 2005/12/05 20:50:53 rillig Exp $

PKGNAME=	ghostscript-gnu-x11-${GS_VERS}
COMMENT=	GNU Postscript interpreter with X11 and image drivers only

CONFIGURE_ARGS+=	--with-x

# Based on the definitions for the DEVICE_DEVS* from ${WRKSRC}/src/devs.mak,
# we clear the ones related to printer devices and preserve the display and
# image devices.
#
.for N in 2 3 4 6 16 17 18 19 20
MAKE_FLAGS+=	DEVICE_DEVS${N}=
.endfor

# We keep the IJS client driver as it's a modular driver, and allows us some
# access to real printers.
#
MAKE_FLAGS+=	DEVICE_DEVS5="\$$(DD)ijs.dev"

.include "../../mk/x11.buildlink3.mk"
.include "../../print/ghostscript-gnu/Makefile.common"
