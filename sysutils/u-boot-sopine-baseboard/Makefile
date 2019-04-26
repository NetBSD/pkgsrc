# $NetBSD: Makefile,v 1.5 2019/04/26 08:32:30 skrll Exp $

UBOOT_TARGET=		sopine-baseboard
UBOOT_CONFIG=		sopine_baseboard_defconfig
UBOOT_BIN=		u-boot-sunxi-with-spl.bin
UBOOT_ENV+=		DEVICE_TREE=sun50i-a64-sopine-baseboard

PKGREVISION=		4

# Switch to EL1 before booting kernel (required for 32-bit support)
PKG_DEFAULT_OPTIONS+=	el1

post-extract:
	${CP} ${PREFIX}/share/arm-trusted-firmware/sun50i_a64/bl31.bin ${WRKSRC}
	${CP} ${WRKSRC}/arch/arm/dts/sun50i-a64-pine64-plus.dts \
	    ${WRKSRC}/arch/arm/dts/sun50i-a64-sopine-baseboard.dts
	${CAT} ${WRKSRC}/configs/${UBOOT_CONFIG} | \
	    ${SED} "s/sun50i-a64-pine64-plus/sun50i-a64-sopine-baseboard/" \
	    > ${WRKSRC}/configs/${UBOOT_CONFIG}.tmp && \
	    ${MV} ${WRKSRC}/configs/${UBOOT_CONFIG}.tmp ${WRKSRC}/configs/${UBOOT_CONFIG}

post-build:
	${CAT} ${WRKSRC}/spl/sunxi-spl.bin ${WRKSRC}/u-boot.itb > ${WRKSRC}/u-boot-sunxi-with-spl.bin

.include "../../sysutils/arm-trusted-firmware-sun50i_a64/buildlink3.mk"
.include "../../sysutils/u-boot/u-boot-arm64.mk"
