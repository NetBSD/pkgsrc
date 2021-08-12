# $NetBSD: Makefile,v 1.2 2021/08/12 07:30:23 wiz Exp $

UBOOT_VERSION=		2021.01-rc3
UBOOT_TARGET=		pinephone
UBOOT_CONFIG=		pinephone_defconfig
UBOOT_BIN=		u-boot-sunxi-with-spl.bin

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

DISTINFO_FILE=		${.CURDIR}/../../sysutils/u-boot-pinephone/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/u-boot-pinephone/patches

TOOL_DEPENDS+=		${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools

ALL_ENV+=		PYTHON3=${PYTHONBIN}

SUBST_CLASSES+=		python3
SUBST_STAGE.python3+=	pre-build
SUBST_FILES.python3+=	Makefile
SUBST_SED.python3+=	-e 's,^PYTHON3.*=.*python3$$,PYTHON3='${PYTHONBIN:Q}',g'

REPLACE_INTERPRETER+=	python3
REPLACE.python3.old+=	/usr/bin/env python3
REPLACE.python3.new+=	${PYTHONBIN}
REPLACE_FILES.python3+=	scripts/dtc/pylibfdt/setup.py

CHECK_PORTABILITY_SKIP+=	tools/imx_cntr_image.sh

post-extract:
	${CP} ${PREFIX}/share/arm-trusted-firmware/sun50i_a64/bl31.bin ${WRKSRC}

.include "../../sysutils/arm-trusted-firmware-sun50i_a64/buildlink3.mk"
.include "../../sysutils/u-boot/u-boot-arm64.mk"
.include "../../mk/bsd.pkg.mk"
