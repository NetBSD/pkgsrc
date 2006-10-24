# $NetBSD: Makefile,v 1.8 2006/10/24 21:01:18 rillig Exp $

DISTNAME=	usrp-0.12
PKGREVISION=	2
COMMENT=	Non GNU Radio specific part of the USRP code base

BUILD_DEPENDS+=	sdcc>=2.4.0:../../devel/sdcc

PYTHON_PATCH_SCRIPTS	+= firmware/src/common/edit-gpif
PYTHON_PATCH_SCRIPTS	+= firmware/src/common/build_eeprom.py
PYTHON_PATCH_SCRIPTS	+= firmware/src/usrp2/edit-gpif

CONFIGURE_ARGS+=	--enable-doxygen

.include "../../meta-pkgs/gnuradio/Makefile.common"

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
