# $NetBSD: Makefile,v 1.5 2019/07/26 10:32:32 tnn Exp $

UBOOT_TARGET=		odroid-c2
UBOOT_CONFIG=		odroid-c2_defconfig
UBOOT_BIN=		u-boot.gxbb

UBOOT_INSTALLBOOT_PLIST=installboot.plist

PKGREVISION=		3

DISTINFO_FILE=		${.CURDIR}/../../sysutils/u-boot-odroid-c2/distinfo
DISTFILES=		${DEFAULT_DISTFILES}

#
# Hardkernel-supplied BLxx binaries
#
ODROID=			odroidc2-v2015.01

xBL1_BIN=		bl1.bin.hardkernel
BL1_BIN=		${ODROID}-${xBL1_BIN}
DISTFILES+=		${BL1_BIN}
UBOOT_BIN+=		${xBL1_BIN}
SITES.${BL1_BIN}=	${MASTER_SITE_GITHUB:@url@ \
	-${url}hardkernel/u-boot/raw/${ODROID}/sd_fuse/${xBL1_BIN} @}

xBL2_PKG=		bl2.package
BL2_PKG=		${ODROID}-${xBL2_PKG}
DISTFILES+=		${BL2_PKG}
SITES.${BL2_PKG}=	${MASTER_SITE_GITHUB:@url@ \
	-${url}hardkernel/u-boot/raw/${ODROID}/fip/gxb/${xBL2_PKG} @}

xBL30_BIN=		bl30.bin
BL30_BIN=		${ODROID}-${xBL30_BIN}
DISTFILES+=		${BL30_BIN}
SITES.${BL30_BIN}=	${MASTER_SITE_GITHUB:@url@ \
	-${url}hardkernel/u-boot/raw/${ODROID}/fip/gxb/${xBL30_BIN} @}

xBL301_BIN=		bl301.bin
BL301_BIN=		${ODROID}-${xBL301_BIN}
DISTFILES+=		${BL301_BIN}
SITES.${BL301_BIN}=	${MASTER_SITE_GITHUB:@url@ \
	-${url}hardkernel/u-boot/raw/${ODROID}/fip/gxb/${xBL301_BIN} @}

xBL31_BIN=		bl31.bin
BL31_BIN=		${ODROID}-${xBL31_BIN}
DISTFILES+=		${BL31_BIN}
SITES.${BL31_BIN}=	${MASTER_SITE_GITHUB:@url@ \
	-${url}hardkernel/u-boot/raw/${ODROID}/fip/gxb/${xBL31_BIN} @}

# pkgsrc tries to run distfiles that end in .bin; handle manually
EXTRACT_ONLY=		${DISTFILES:N*.bin}

post-extract:
	cp ${DISTDIR}/${BL1_BIN} ${WRKSRC}/${xBL1_BIN}
	cp ${DISTDIR}/${BL2_PKG} ${WRKSRC}/${xBL2_PKG}
	cp ${DISTDIR}/${BL30_BIN} ${WRKSRC}/${xBL30_BIN}
	cp ${DISTDIR}/${BL301_BIN} ${WRKSRC}/${xBL301_BIN}
	cp ${DISTDIR}/${BL31_BIN} ${WRKSRC}/${xBL31_BIN}

#
# XXX For now, we use the fip_create and aml_encrypt_gxb binaries
# from Hardkernel.
#
BUILD_DEPENDS+=		amlogic-meson-fwtools>=0.0:../../sysutils/amlogic-meson-fwtools
post-build:
	${PREFIX}/bin/aml_fip_create \
		--bl30 ${WRKSRC}/${xBL30_BIN} \
		--bl301 ${WRKSRC}/${xBL301_BIN} \
		--bl31 ${WRKSRC}/${xBL31_BIN} \
		--bl33 ${WRKSRC}/u-boot-dtb.bin \
		${WRKSRC}/u-boot-fip.bin
	${PREFIX}/bin/aml_fip_create --dump ${WRKSRC}/u-boot-fip.bin
	cat ${WRKSRC}/${xBL2_PKG} ${WRKSRC}/u-boot-fip.bin > \
		${WRKSRC}/u-boot-combined.bin
	${PREFIX}/bin/aml_encrypt_gxb --bootsig \
		--input ${WRKSRC}/u-boot-combined.bin \
		--output ${WRKSRC}/u-boot.img
	dd if=${WRKSRC}/u-boot.img of=${WRKSRC}/u-boot.gxbb \
		bs=512 skip=96

# XXX We'd prefer this, but fiptool doesn't create a working image
# for Odroid-C2.
#BUILD_DEPENDS+=	arm-trusted-firmware-fiptool>=2.0nb2:../../sysutils/arm-trusted-firmware-fiptool
#x-post-build-tf-a:
#	fiptool create --align 0x4000 \
#		--scp-fw ${WRKSRC}/${xBL30_BIN} \
#		--blob uuid=DDCCBBAA-CDAB-EFEF-ABCD-12345678ABCD,file=${WRKSRC}/${xBL301_BIN} \
#		--soc-fw ${WRKSRC}/${xBL31_BIN} \
#		--nt-fw ${WRKSRC}/u-boot-dtb.bin \
#		${WRKSRC}/u-boot-fip.bin
#	fiptool info ${WRKSRC}/u-boot-fip.bin
#	cat ${WRKSRC}/${xBL2_PKG} ${WRKSRC}/u-boot-fip.bin > \
#		${WRKSRC}/u-boot-combined.bin
#	aml_encrypt_gxb --bootsig \
#		--input ${WRKSRC}/u-boot-combined.bin \
#		--output ${WRKSRC}/u-boot.img
#	dd if=${WRKSRC}/u-boot.img of=${WRKSRC}/u-boot.gxbb \
#		bs=512 skip=96

.include "../../sysutils/u-boot/u-boot-arm64.mk"
