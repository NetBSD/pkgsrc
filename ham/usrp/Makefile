# $NetBSD: Makefile,v 1.1.1.1 2005/10/07 23:19:15 wulf Exp $

DISTNAME=	usrp-0.8
COMMENT=	Non GNU Radio specific part of the USRP code base

BUILD_DEPENDS+=	sdcc>=2.4.0:../../devel/sdcc

post-install:
	${INSTALL_DATA} ${WRKSRC}/fpga/rbf/usrp_fpga_rev2.rbf  \
		${LOCALBASE}/share/usrp/rev2/usrp_fpga.rbf

.include "../../meta-pkgs/gnuradio/Makefile.common"

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
