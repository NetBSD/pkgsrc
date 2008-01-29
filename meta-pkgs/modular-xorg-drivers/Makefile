# $NetBSD: Makefile,v 1.8 2008/01/29 13:58:35 abs Exp $

DISTNAME=	# empty
PKGNAME=	modular-xorg-drivers-1.1
PKGREVISION=	2
CATEGORIES=	meta-pkgs drivers x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/drivers
DISTFILES=	# empty

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg driver meta-package

.include "../../mk/bsd.prefs.mk"

DEPENDS+=	xf86-input-keyboard-[0-9]*:../../x11/xf86-input-keyboard
DEPENDS+=	xf86-input-mouse-[0-9]*:../../x11/xf86-input-mouse
DEPENDS+=	xf86-input-void-[0-9]*:../../x11/xf86-input-void
DEPENDS+=	xf86-video-apm-[0-9]*:../../x11/xf86-video-apm
DEPENDS+=	xf86-video-ark-[0-9]*:../../x11/xf86-video-ark
DEPENDS+=	xf86-video-ast-[0-9]*:../../x11/xf86-video-ast
DEPENDS+=	xf86-video-ati-[0-9]*:../../x11/xf86-video-ati
DEPENDS+=	xf86-video-chips-[0-9]*:../../x11/xf86-video-chips
DEPENDS+=	xf86-video-cirrus-[0-9]*:../../x11/xf86-video-cirrus
DEPENDS+=	xf86-video-cyrix-[0-9]*:../../x11/xf86-video-cyrix
DEPENDS+=	xf86-video-glint-[0-9]*:../../x11/xf86-video-glint
DEPENDS+=	xf86-video-i128-[0-9]*:../../x11/xf86-video-i128
DEPENDS+=	xf86-video-i740-[0-9]*:../../x11/xf86-video-i740
DEPENDS+=	xf86-video-imstt-[0-9]*:../../x11/xf86-video-imstt
DEPENDS+=	xf86-video-intel-[0-9]*:../../x11/xf86-video-intel
DEPENDS+=	xf86-video-mga-[0-9]*:../../x11/xf86-video-mga
DEPENDS+=	xf86-video-neomagic-[0-9]*:../../x11/xf86-video-neomagic
DEPENDS+=	xf86-video-nsc-[0-9]*:../../x11/xf86-video-nsc
DEPENDS+=	xf86-video-nv-[0-9]*:../../x11/xf86-video-nv
DEPENDS+=	xf86-video-radeonhd-[0-9]*:../../x11/xf86-video-radeonhd
DEPENDS+=	xf86-video-rendition-[0-9]*:../../x11/xf86-video-rendition
DEPENDS+=	xf86-video-s3-[0-9]*:../../x11/xf86-video-s3
DEPENDS+=	xf86-video-s3virge-[0-9]*:../../x11/xf86-video-s3virge
DEPENDS+=	xf86-video-savage-[0-9]*:../../x11/xf86-video-savage
DEPENDS+=	xf86-video-siliconmotion-[0-9]*:../../x11/xf86-video-siliconmotion
DEPENDS+=	xf86-video-sis-[0-9]*:../../x11/xf86-video-sis
DEPENDS+=	xf86-video-tdfx-[0-9]*:../../x11/xf86-video-tdfx
DEPENDS+=	xf86-video-tga-[0-9]*:../../x11/xf86-video-tga
DEPENDS+=	xf86-video-trident-[0-9]*:../../x11/xf86-video-trident
DEPENDS+=	xf86-video-tseng-[0-9]*:../../x11/xf86-video-tseng
DEPENDS+=	xf86-video-vesa-[0-9]*:../../x11/xf86-video-vesa
DEPENDS+=	xf86-video-vga-[0-9]*:../../x11/xf86-video-vga
DEPENDS+=	xf86-video-via-[0-9]*:../../x11/xf86-video-via
DEPENDS+=	xf86-video-vmware-[0-9]*:../../x11/xf86-video-vmware
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD"
DEPENDS+=	xf86-video-wsfb-[0-9]*:../../x11/xf86-video-wsfb
.endif

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
