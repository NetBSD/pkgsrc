# $NetBSD: Makefile,v 1.13 2010/03/24 19:43:24 asau Exp $

PKGNAME=	usrp-${VERSION}
PKGREVISION=	2
COMMENT=	Non GNU Radio specific part of the USRP code base

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONFIGURE_ARGS+=	--enable-usrp
CONFIGURE_ARGS+=--with-gnuradio-core --with-omnithread --with-gruel

BUILD_DEPENDS+=	sdcc>=2.4.0:../../devel/sdcc

PYTHON_PATCH_SCRIPTS+=	usrp/firmware/include/generate_regs.py
PYTHON_PATCH_SCRIPTS+=	usrp/firmware/src/common/edit-gpif
PYTHON_PATCH_SCRIPTS+=	usrp/firmware/src/common/build_eeprom.py
PYTHON_PATCH_SCRIPTS+=	usrp/firmware/src/usrp2/edit-gpif
PYTHON_PATCH_SCRIPTS+=	usrp/fpga/gen_makefile_extra.py
PYTHON_PATCH_SCRIPTS+=	usrp/fpga/sdr_lib/gen_cordic_consts.py
PYTHON_PATCH_SCRIPTS+=	usrp/fpga/toplevel/mrfm/mrfm.py
PYTHON_PATCH_SCRIPTS+=	usrp/fpga/toplevel/mrfm/mrfm_fft.py
PYTHON_PATCH_SCRIPTS+=	usrp/host/lib/check_data.py
PYTHON_PATCH_SCRIPTS+=	usrp/host/lib/dump_data.py
PYTHON_PATCH_SCRIPTS+=	usrp/host/lib/gen_usrp_dbid.py
PYTHON_PATCH_SCRIPTS+=	usrp/host/lib/usrp_dbid.py

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
