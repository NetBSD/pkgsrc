# $NetBSD: Makefile,v 1.7 2006/07/07 19:31:14 wiz Exp $

DISTNAME=	usrp-0.12
PKGREVISION=	1
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
