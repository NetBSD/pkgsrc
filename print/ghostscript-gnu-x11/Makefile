# $NetBSD: Makefile,v 1.2 2002/09/13 22:27:12 jlam Exp $

PKGNAME=	ghostscript-gnu-x11-${GS_VERS}
PKGREVISION=	1
COMMENT=	GNU Postscript interpreter with X11 and image drivers

USE_X11=		# defined
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

.include "../ghostscript-gnu/Makefile.common"
