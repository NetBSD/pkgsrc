# $NetBSD: Makefile,v 1.1.1.1 2015/10/18 12:20:51 jmcneill Exp $

DISTNAME=	tegra-firmware-20151018
CATEGORIES=	sysutils
MASTER_SITES=	http://ftp.NetBSD.org/pub/NetBSD/misc/jmcneill/tegra/

MAINTAINER=	jmcneill@invisible.ca
HOMEPAGE=	http://git.kernel.org/cgit/linux/kernel/git/firmware/linux-firmware.git/
COMMENT=	Firmware binary images for NVIDIA Tegra SOCs
LICENSE=	nvidia-firmware-license

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	libdata/nvidia libdata/nvidia/gk20a \
			libdata/nvidia/tegra124 libdata/nvidia/tegra210

GK20A_FILES=	fecs_data.bin fecs_inst.bin gpccs_data.bin gpccs_inst.bin \
		sw_bundle_init.bin sw_ctx.bin sw_method_init.bin sw_nonctx.bin
TEGRA124_FILES=	xusb.bin
TEGRA210_FILES=	xusb.bin

do-install:
	${INSTALL_DATA} ${WRKSRC}/LICENCE.nvidia ${DESTDIR}${PREFIX}/libdata/nvidia/
.for s in ${GK20A_FILES}
	${INSTALL_DATA} ${WRKSRC}/nvidia/gk20a/${s} ${DESTDIR}${PREFIX}/libdata/nvidia/gk20a/
.endfor
.for s in ${TEGRA124_FILES}
	${INSTALL_DATA} ${WRKSRC}/nvidia/tegra124/${s} ${DESTDIR}${PREFIX}/libdata/nvidia/tegra124/
.endfor
.for s in ${TEGRA210_FILES}
	${INSTALL_DATA} ${WRKSRC}/nvidia/tegra210/${s} ${DESTDIR}${PREFIX}/libdata/nvidia/tegra210/
.endfor

.include "../../mk/bsd.pkg.mk"
