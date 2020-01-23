#	$NetBSD: u-boot-rockchip.mk,v 1.2 2020/01/23 18:26:35 jakllsch Exp $
#
# should be used by sysutils/u-boot-rock64/Makefile
# used by sysutils/u-boot-rockpro64/Makefile
# used by sysutils/u-boot-pinebook-pro/Makefile

# Common makefile fragment for rockchip based u-boot targets.
#
# Set these variables:
#
#	U_BOOT_IMAGE_TYPE	("rk3399", "rk3328")
#

UBOOT_VERSION?=		2020.01-rc5

# Patches kept in pinebook-pro; first worked there.
DISTINFO_FILE?=		${.CURDIR}/../../sysutils/u-boot-pinebook-pro/distinfo
PATCHDIR?=		${.CURDIR}/../../sysutils/u-boot-pinebook-pro/patches

MAKE_ENV+=		BL31=${PREFIX}/share/arm-trusted-firmware/${U_BOOT_IMAGE_TYPE}/bl31.elf

post-build:
# wrap everything up into a single file that can be written to an SD card
	cp ${WRKSRC}/idbloader.img ${WRKSRC}/rksd_loader.img
	dd if=${WRKSRC}/u-boot.itb seek=448 conv=notrunc of=${WRKSRC}/rksd_loader.img
# build SPI NOR flash image. See dev-ayufan/build.mk.
	set -e; b=0; while [ "$$b" != 128 ]; do \
		dd bs=2k count=1; \
		dd if=/dev/zero bs=2k count=1; \
		b=$$(expr $$b + 1); \
	done < ${WRKSRC}/idbloader.img > ${WRKSRC}/rkspi_loader.img 2> /dev/null
	dd if=${WRKSRC}/u-boot.itb seek=1024 conv=notrunc of=${WRKSRC}/rkspi_loader.img

SUBST_CLASSES+=			makefitpath
SUBST_STAGE.makefitpath=	pre-configure
SUBST_FILES.makefitpath=	arch/arm/mach-rockchip/make_fit_atf.py
SUBST_SED.makefitpath=		-e "s| python3| python|g"

PYTHON_VERSIONS_ACCEPTED+=	37 38
REPLACE_INTERPRETER+=	python3
REPLACE.python3.old=	python3
REPLACE.python3.new=	${PYTHON3BIN}
REPLACE_FILES.python2=	arch/arm/mach-rockchip/make_fit_atf.py

.include "../../sysutils/arm-trusted-firmware-${U_BOOT_IMAGE_TYPE}/buildlink3.mk"
.include "../../sysutils/u-boot/u-boot-arm64.mk"
