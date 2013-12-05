# $NetBSD: Makefile,v 1.1 2013/12/05 11:42:15 obache Exp $

DISTNAME=	suse_glx-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	Mesa-9.2.2-61.6.1.${SUSE_ARCH}
RPMPKGS+=	Mesa-libEGL1-9.2.2-61.6.1.${SUSE_ARCH}
RPMPKGS+=	Mesa-libGL1-9.2.2-61.6.1.${SUSE_ARCH}
RPMPKGS+=	Mesa-libglapi0-9.2.2-61.6.1.${SUSE_ARCH}
RPMPKGS+=	libgbm1-9.2.2-61.6.1.${SUSE_ARCH}
RPMPKGS+=	libwayland-client0-1.2.1-1.1.${SUSE_ARCH}
RPMPKGS+=	libwayland-server0-1.2.1-1.1.${SUSE_ARCH}
RPMPKGS+=	libudev1-208-6.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for OpenGL/Mesa

EMUL_MODULES.linux=	x11 drm

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
