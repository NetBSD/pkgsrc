# $NetBSD: Makefile,v 1.2 2026/06/08 09:17:36 wiz Exp $

UBOOT_TARGET=		imx8mq-phanbell
UBOOT_CONFIG=		imx8mq_phanbell_defconfig
UBOOT_BIN=		flash.bin

UBOOT_VERSION=		2022.01

BUILD_DEPENDS+=		firmware-imx>=8.31:../../sysutils/firmware-imx

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

BIN_FILES=	ddr/synopsys/lpddr4_pmu_train_1d_dmem.bin \
		ddr/synopsys/lpddr4_pmu_train_1d_imem.bin \
		ddr/synopsys/lpddr4_pmu_train_2d_dmem.bin \
		ddr/synopsys/lpddr4_pmu_train_2d_imem.bin \
		hdmi/cadence/signed_hdmi_imx8m.bin

post-extract:
	${CP} ${PREFIX}/share/trusted-firmware-a/imx8mq/bl31.bin ${WRKSRC}
	cd ${PREFIX}/libdata/firmware/imx && ${CP} ${BIN_FILES} ${WRKSRC}

.include "../../sysutils/trusted-firmware-a-imx8mq/buildlink3.mk"
.include "../../sysutils/u-boot/u-boot-arm64.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
