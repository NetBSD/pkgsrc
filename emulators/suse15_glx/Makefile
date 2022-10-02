# $NetBSD: Makefile,v 1.1 2022/10/02 17:17:18 wiz Exp $

PKGNAME=	suse_glx-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	Mesa-21.2.4-150400.68.9.1.${SUSE_ARCH}
RPMPKGS+=	Mesa-dri-21.2.4-150400.68.9.1.${SUSE_ARCH}
RPMPKGS+=	Mesa-dri-nouveau-21.2.4-150400.68.9.1.${SUSE_ARCH}
RPMPKGS+=	Mesa-gallium-21.2.4-150400.68.9.1.${SUSE_ARCH}
RPMPKGS+=	Mesa-libEGL1-21.2.4-150400.68.9.1.${SUSE_ARCH}
RPMPKGS+=	Mesa-libGL1-21.2.4-150400.68.9.1.${SUSE_ARCH}
RPMPKGS+=	Mesa-libglapi0-21.2.4-150400.68.9.1.${SUSE_ARCH}
RPMPKGS+=	libGLU1-9.0.0-8.45.${SUSE_ARCH}
RPMPKGS+=	libLLVM11-11.0.1-1.26.${SUSE_ARCH} # needed by swrast_dri.so
RPMPKGS+=	libedit0-3.1.snap20150325-2.12.${SUSE_ARCH}
RPMPKGS+=	libelf1-0.185-150400.5.3.1.${SUSE_ARCH}
RPMPKGS+=	libgbm1-21.2.4-150400.68.9.1.${SUSE_ARCH}
RPMPKGS+=	libudev1-249.12-150400.8.10.1.${SUSE_ARCH}
RPMPKGS+=	libglvnd-1.3.3-150400.3.4.${SUSE_ARCH}
RPMPKGS+=	libpciaccess0-0.14-1.16.${SUSE_ARCH}
RPMPKGS+=	libwayland-client0-1.19.0-150400.1.4.${SUSE_ARCH}
RPMPKGS+=	libwayland-server0-1.19.0-150400.1.4.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for OpenGL/Mesa

EMUL_MODULES.linux=	expat x11 drm

.include "../../emulators/suse15_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
