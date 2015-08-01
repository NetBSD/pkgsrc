# $NetBSD: Makefile,v 1.10.4.1 2015/08/01 09:19:56 tron Exp $

PKGNAME=	suse_x11-${SUSE_VERSION}
PKGREVISION=	6
CATEGORIES=	emulators
RPMPKGS+=	libFS6-1.0.5-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libICE6-1.0.8-7.1.2.${SUSE_ARCH}
RPMPKGS+=	libSM6-1.2.2-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libWindowsWM7-1.0.1-9.1.2.${SUSE_ARCH}
RPMPKGS+=	libX11-6-1.6.2-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libX11-data-1.6.2-2.1.2.noarch
RPMPKGS+=	libX11-xcb1-1.6.2-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libXau6-1.0.8-2.2.1.${SUSE_ARCH}
RPMPKGS+=	libXaw6-1.0.12-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libXaw7-1.0.12-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libXaw8-1.0.12-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libXcliplist1-20070501-8.1.2.${SUSE_ARCH}
RPMPKGS+=	libXcomposite1-0.4.4-6.1.2.${SUSE_ARCH}
RPMPKGS+=	libXcursor1-1.1.14-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libXdamage1-1.1.4-6.1.2.${SUSE_ARCH}
RPMPKGS+=	libXdmcp6-1.1.1-7.1.2.${SUSE_ARCH}
RPMPKGS+=	libXext6-1.3.2-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libXevie1-1.0.3-9.1.2.${SUSE_ARCH}
RPMPKGS+=	libXfixes3-5.0.1-2.1.2.${SUSE_ARCH}
RPMUPDPKGS+=	libXfont1-1.4.6-2.12.1.${SUSE_ARCH}
RPMPKGS+=	libXfontcache1-1.0.5-9.1.2.${SUSE_ARCH}
RPMPKGS+=	libXft2-2.3.1-7.1.2.${SUSE_ARCH}
RPMPKGS+=	libXi6-1.7.2-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libXinerama1-1.1.3-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libXmu6-1.1.2-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libXp6-1.0.2-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libXpm4-3.5.11-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libXprintAppUtil1-1.0.1-9.1.2.${SUSE_ARCH}
RPMPKGS+=	libXprintUtil1-1.0.1-9.1.2.${SUSE_ARCH}
RPMPKGS+=	libXrender1-0.9.8-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libXss1-1.2.2-7.1.2.${SUSE_ARCH}
RPMPKGS+=	libXt6-1.1.4-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libXtst6-1.2.2-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libXv1-1.0.10-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libXvMC1-1.0.8-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libXrandr2-1.4.2-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libXRes1-1.0.7-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libXTrap6-1.0.1-6.1.2.${SUSE_ARCH}
RPMPKGS+=	libXxf86dga1-1.1.4-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libXxf86misc1-1.0.3-9.1.2.${SUSE_ARCH}
RPMPKGS+=	libXxf86vm1-1.1.3-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libdmx1-1.1.3-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libfontenc1-1.1.2-2.1.2.${SUSE_ARCH}
RPMPKGS+=	liblbxutil1-1.1.0-9.1.2.${SUSE_ARCH}
RPMPKGS+=	liboldX6-1.0.1-8.1.2.${SUSE_ARCH}
RPMUPDPKGS+=	libpixman-1-0-0.30.2-2.5.1.${SUSE_ARCH}
RPMPKGS+=	libxcb1-1.9.1-3.1.2.${SUSE_ARCH}
RPMPKGS+=	libxcb-dri2-0-1.9.1-3.1.2.${SUSE_ARCH}
RPMPKGS+=	libxcb-glx0-1.9.1-3.1.2.${SUSE_ARCH}
RPMPKGS+=	libxcb-render0-1.9.1-3.1.2.${SUSE_ARCH}
RPMPKGS+=	libxcb-shm0-1.9.1-3.1.2.${SUSE_ARCH}
RPMPKGS+=	libxcb-xfixes0-1.9.1-3.1.2.${SUSE_ARCH}
RPMPKGS+=	libxkbfile1-1.0.8-7.1.2.${SUSE_ARCH}
RPMPKGS+=	libxkbui1-1.0.2-9.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for X11

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
