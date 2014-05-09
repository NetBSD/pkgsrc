# $NetBSD: Makefile,v 1.28 2014/05/09 07:37:08 wiz Exp $

PKGNAME=	usrp-${VERSION}
PKGREVISION=	10
COMMENT=	Non GNU Radio specific part of the USRP code base

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 3.3.0

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONFIGURE_ARGS+=	--enable-usrp
CONFIGURE_ARGS+=--with-gnuradio-core --with-omnithread --with-gruel

BUILD_DEPENDS+=	sdcc>=2.4.0<3:../../devel/sdcc

REPLACE_PYTHON+=	usrp/firmware/include/generate_regs.py
REPLACE_PYTHON+=	usrp/firmware/src/common/edit-gpif
REPLACE_PYTHON+=	usrp/firmware/src/common/build_eeprom.py
REPLACE_PYTHON+=	usrp/firmware/src/usrp2/edit-gpif
REPLACE_PYTHON+=	usrp/host/lib/check_data.py
REPLACE_PYTHON+=	usrp/host/lib/dump_data.py
REPLACE_PYTHON+=	usrp/host/lib/gen_usrp_dbid.py
REPLACE_PYTHON+=	usrp/host/lib/usrp_dbid.py

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
