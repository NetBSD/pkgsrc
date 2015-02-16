# $NetBSD: Makefile,v 1.5 2015/02/16 10:15:45 jperkin Exp $

PKGNAME=	suse_glx-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
RPMPKGS+=	Mesa-7.11-11.1.2.${SUSE_ARCH}
RPMPKGS+=	libudev0-173-3.3.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for OpenGL/Mesa

EMUL_MODULES.linux=	x11 drm

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
