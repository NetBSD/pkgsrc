# $NetBSD: Makefile,v 1.1.1.1 2012/03/21 13:41:10 obache Exp $

DISTNAME=	suse_x11-${SUSE_VERSION}
CATEGORIES=	emulators
RPMUPDPKGS+=	libpixman-1-0-0.24.0-2.3.1.${SUSE_ARCH}
RPMPKGS+=	libXi6-1.4.0-10.1.2.${SUSE_ARCH}
RPMPKGS+=	xorg-x11-libs-7.6-25.1.2.${SUSE_ARCH}
RPMPKGS+=	xorg-x11-libfontenc-7.6-9.1.2.${SUSE_ARCH}
RPMPKGS+=	xorg-x11-libICE-7.6-11.1.2.${SUSE_ARCH}
RPMPKGS+=	xorg-x11-libSM-7.6-10.1.2.${SUSE_ARCH}
RPMPKGS+=	xorg-x11-libX11-7.6-23.1.2.${SUSE_ARCH}
RPMPKGS+=	xorg-x11-libXau-7.6_1.0.6-9.1.2.${SUSE_ARCH}
RPMPKGS+=	xorg-x11-libxcb-7.6_1.7-11.1.2.${SUSE_ARCH}
RPMPKGS+=	xorg-x11-libXdmcp-7.6-10.1.2.${SUSE_ARCH}
RPMPKGS+=	xorg-x11-libXext-7.6_1.2.0-5.1.2.${SUSE_ARCH}
RPMPKGS+=	xorg-x11-libXfixes-7.6_5.0-3.1.2.${SUSE_ARCH}
RPMPKGS+=	xorg-x11-libxkbfile-7.6-9.1.2.${SUSE_ARCH}
RPMPKGS+=	xorg-x11-libXmu-7.6-10.1.2.${SUSE_ARCH}
RPMPKGS+=	xorg-x11-libXp-7.6-5.1.2.${SUSE_ARCH}
RPMPKGS+=	xorg-x11-libXpm-7.6-9.1.2.${SUSE_ARCH}
RPMPKGS+=	xorg-x11-libXprintUtil-7.6-5.1.2.${SUSE_ARCH}
RPMPKGS+=	xorg-x11-libXrender-7.6_0.9.6-9.1.2.${SUSE_ARCH}
RPMPKGS+=	xorg-x11-libXt-7.6_1.0.9-14.1.2.${SUSE_ARCH}
RPMPKGS+=	xorg-x11-libXv-7.6-9.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for X11

EMUL_MODULES.linux=	base

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
