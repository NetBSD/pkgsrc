# $NetBSD: Makefile,v 1.21 2012/10/03 13:01:46 asau Exp $

PKGNAME=	usrp-${VERSION}
PKGREVISION=	7
COMMENT=	Non GNU Radio specific part of the USRP code base

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONFIGURE_ARGS+=	--enable-usrp
CONFIGURE_ARGS+=--with-gnuradio-core --with-omnithread --with-gruel

BUILD_DEPENDS+=	sdcc>=2.4.0:../../devel/sdcc

PYTHON_PATCH_SCRIPTS+=	usrp/firmware/include/generate_regs.py
PYTHON_PATCH_SCRIPTS+=	usrp/firmware/src/common/edit-gpif
PYTHON_PATCH_SCRIPTS+=	usrp/firmware/src/common/build_eeprom.py
PYTHON_PATCH_SCRIPTS+=	usrp/firmware/src/usrp2/edit-gpif
PYTHON_PATCH_SCRIPTS+=	usrp/host/lib/check_data.py
PYTHON_PATCH_SCRIPTS+=	usrp/host/lib/dump_data.py
PYTHON_PATCH_SCRIPTS+=	usrp/host/lib/gen_usrp_dbid.py
PYTHON_PATCH_SCRIPTS+=	usrp/host/lib/usrp_dbid.py

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
