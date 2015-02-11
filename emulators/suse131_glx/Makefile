# $NetBSD: Makefile,v 1.7 2015/02/11 09:38:17 obache Exp $

DISTNAME=	suse_glx-${SUSE_VERSION}
PKGREVISION=	2
CATEGORIES=	emulators
RPMUPDPKGS+=	Mesa-9.2.3-61.9.1.${SUSE_ARCH}
RPMUPDPKGS+=	Mesa-libEGL1-9.2.3-61.9.1.${SUSE_ARCH}
RPMUPDPKGS+=	Mesa-libGL1-9.2.3-61.9.1.${SUSE_ARCH}
RPMUPDPKGS+=	Mesa-libglapi0-9.2.3-61.9.1.${SUSE_ARCH}
RPMUPDPKGS+=	libgbm1-9.2.3-61.9.1.${SUSE_ARCH}
RPMPKGS+=	libGLU1-9.0.0-7.1.2.${SUSE_ARCH}
RPMPKGS+=	libwayland-client0-1.2.1-1.1.${SUSE_ARCH}
RPMPKGS+=	libwayland-server0-1.2.1-1.1.${SUSE_ARCH}
RPMPKGS+=	libudev1-208-6.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for OpenGL/Mesa

EMUL_MODULES.linux=	x11 drm

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
