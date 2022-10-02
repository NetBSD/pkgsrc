# $NetBSD: Makefile,v 1.1 2022/10/02 17:17:18 wiz Exp $

PKGNAME=	suse_libdrm-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libdrm2-2.4.107-150400.1.8.${SUSE_ARCH}
RPMPKGS+=	libdrm_amdgpu1-2.4.107-150400.1.8.${SUSE_ARCH}
RPMPKGS+=	libdrm_intel1-2.4.107-150400.1.8.${SUSE_ARCH}
RPMPKGS+=	libdrm_nouveau2-2.4.107-150400.1.8.${SUSE_ARCH}
RPMPKGS+=	libdrm_radeon1-2.4.107-150400.1.8.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for libdrm

EMUL_MODULES.linux=	x11

.include "../../emulators/suse15_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
