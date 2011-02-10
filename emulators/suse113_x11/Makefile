# $NetBSD: Makefile,v 1.2 2011/02/10 02:55:49 chs Exp $

DISTNAME=	suse_x11-${SUSE_VERSION}
CATEGORIES=	emulators
DISTFILES=	\
	libpixman-1-0-0.18.0-1.10.${SUSE_ARCH}.rpm		\
	libXi6-1.3-1.9.${SUSE_ARCH}.rpm				\
	xorg-x11-libs-7.5-3.15.${SUSE_ARCH}.rpm			\
	xorg-x11-libfontenc-7.5-1.9.${SUSE_ARCH}.rpm		\
	xorg-x11-libICE-7.5-1.9.${SUSE_ARCH}.rpm		\
	xorg-x11-libSM-7.5-1.11.${SUSE_ARCH}.rpm		\
	xorg-x11-libX11-7.5-1.23.${SUSE_ARCH}.rpm		\
	xorg-x11-libXau-7.5-1.9.${SUSE_ARCH}.rpm		\
	xorg-x11-libxcb-7.5-3.1.${SUSE_ARCH}.rpm		\
	xorg-x11-libXdmcp-7.5-1.9.${SUSE_ARCH}.rpm		\
	xorg-x11-libXext-7.5-1.10.${SUSE_ARCH}.rpm		\
	xorg-x11-libXfixes-7.5-1.9.${SUSE_ARCH}.rpm		\
	xorg-x11-libxkbfile-7.5-1.9.${SUSE_ARCH}.rpm		\
	xorg-x11-libXmu-7.5-1.9.${SUSE_ARCH}.rpm		\
	xorg-x11-libXp-7.5-1.9.${SUSE_ARCH}.rpm			\
	xorg-x11-libXpm-7.5-1.9.${SUSE_ARCH}.rpm		\
	xorg-x11-libXprintUtil-7.5-1.10.${SUSE_ARCH}.rpm 	\
	xorg-x11-libXrender-7.5-1.9.${SUSE_ARCH}.rpm		\
	xorg-x11-libXt-7.5-1.10.${SUSE_ARCH}.rpm		\
	xorg-x11-libXv-7.5-1.8.${SUSE_ARCH}.rpm


MAINTAINER=	chs@NetBSD.org
COMMENT=	Linux compatibility package for X11

EMUL_MODULES.linux=	base

.include "../../emulators/suse113_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
