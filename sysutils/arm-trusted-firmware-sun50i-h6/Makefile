# $NetBSD: Makefile,v 1.4 2020/06/30 14:33:16 thorpej Exp $

PLATFORM=	sun50i_h6
PKGNAME=	${GITHUB_PROJECT}-sun50i-h6-${VERSION}	# XXX rename this pkg
COMMENT=	ARM Trusted Firmware for Allwinner H6 SoCs

do-install:	# XXX rename this pkg
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/arm-trusted-firmware/sun50i-h6
	${INSTALL_DATA} ${WRKSRC}/build/sun50i_h6/${BL31_DIR}/bl31.bin \
	    ${DESTDIR}${PREFIX}/share/arm-trusted-firmware/sun50i-h6

.include "../../sysutils/arm-trusted-firmware/arm-trusted-firmware.mk"
