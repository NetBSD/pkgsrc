# $NetBSD: Makefile,v 1.39.2.1 2017/06/05 09:19:29 bsiegert Exp $

DISTNAME=	# empty
PKGNAME=	modular-xorg-drivers-1.19.0
PKGREVISION=	3
CATEGORIES=	meta-pkgs x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
DISTFILES=	# empty

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg driver meta-package
LICENSE=	2-clause-bsd

META_PACKAGE=	yes

.include "../../mk/bsd.prefs.mk"

DEPENDS+=	xf86-input-acecad-[0-9]*:../../x11/xf86-input-acecad
DEPENDS+=	xf86-input-keyboard-[0-9]*:../../x11/xf86-input-keyboard
DEPENDS+=	xf86-input-mouse-[0-9]*:../../x11/xf86-input-mouse
DEPENDS+=	xf86-input-penmount-[0-9]*:../../x11/xf86-input-penmount
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
DEPENDS+=	xf86-input-vmmouse-[0-9]*:../../x11/xf86-input-vmmouse
.endif
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD"
DEPENDS+=	xf86-input-ws-[0-9]*:../../x11/xf86-input-ws
.endif
DEPENDS+=	xf86-input-void-[0-9]*:../../x11/xf86-input-void
DEPENDS+=	xf86-video-amdgpu-[0-9]*:../../x11/xf86-video-amdgpu
DEPENDS+=	xf86-video-apm-[0-9]*:../../x11/xf86-video-apm
DEPENDS+=	xf86-video-ark-[0-9]*:../../x11/xf86-video-ark
DEPENDS+=	xf86-video-ast-[0-9]*:../../x11/xf86-video-ast
.if !empty(MACHINE_PLATFORM:MNetBSD-7.*-i386) ||	\
    !empty(MACHINE_PLATFORM:MNetBSD-7.*-x86_64) ||	\
    ${OPSYS} == "Linux" || ${OPSYS} == "FreeBSD" ||	\
    ${OPSYS} == "DragonFly" || ${OPSYS} == "SunOS"
DEPENDS+=	xf86-video-ati-[0-9]*:../../x11/xf86-video-ati
.else
DEPENDS+=	xf86-video-ati6-[0-9]*:../../x11/xf86-video-ati6
.endif
DEPENDS+=	xf86-video-chips-[0-9]*:../../x11/xf86-video-chips
DEPENDS+=	xf86-video-cirrus-[0-9]*:../../x11/xf86-video-cirrus
DEPENDS+=	xf86-video-dummy-[0-9]*:../../x11/xf86-video-dummy
DEPENDS+=	xf86-input-elographics-[0-9]*:../../x11/xf86-input-elographics
DEPENDS+=	xf86-video-fbdev-[0-9]*:../../x11/xf86-video-fbdev
DEPENDS+=	xf86-input-fpit-[0-9]*:../../x11/xf86-input-fpit
DEPENDS+=	xf86-video-glint-[0-9]*:../../x11/xf86-video-glint
DEPENDS+=	xf86-input-hyperpen-[0-9]*:../../x11/xf86-input-hyperpen
DEPENDS+=	xf86-video-i128-[0-9]*:../../x11/xf86-video-i128
DEPENDS+=	xf86-video-i740-[0-9]*:../../x11/xf86-video-i740
DEPENDS+=	xf86-video-intel-[0-9]*:../../x11/xf86-video-intel
.if ${OPSYS} != "SunOS"
DEPENDS+=	xf86-input-joystick-[0-9]*:../../x11/xf86-input-joystick
.endif
DEPENDS+=	xf86-video-mach64-[0-9]*:../../x11/xf86-video-mach64
DEPENDS+=	xf86-video-mga-[0-9]*:../../x11/xf86-video-mga
DEPENDS+=	xf86-input-mutouch-[0-9]*:../../x11/xf86-input-mutouch
# does not work with 1.17 server
.if !empty(USE_OLD_MODULAR_XORG_SERVER:M[yY][eE][sS])
DEPENDS+=	xf86-video-modesetting-[0-9]*:../../x11/xf86-video-modesetting
DEPENDS+=	xf86-video-newport-[0-9]*:../../x11/xf86-video-newport
.endif
DEPENDS+=	xf86-video-neomagic-[0-9]*:../../x11/xf86-video-neomagic
DEPENDS+=	xf86-video-nouveau-[0-9]*:../../x11/xf86-video-nouveau
DEPENDS+=	xf86-video-nv-[0-9]*:../../x11/xf86-video-nv
DEPENDS+=	xf86-video-openchrome-[0-9]*:../../x11/xf86-video-openchrome
DEPENDS+=	xf86-video-qxl-[0-9]*:../../x11/xf86-video-qxl
DEPENDS+=	xf86-video-r128-[0-9]*:../../x11/xf86-video-r128
DEPENDS+=	xf86-video-rendition-[0-9]*:../../x11/xf86-video-rendition
DEPENDS+=	xf86-video-s3-[0-9]*:../../x11/xf86-video-s3
DEPENDS+=	xf86-video-s3virge-[0-9]*:../../x11/xf86-video-s3virge
DEPENDS+=	xf86-video-savage-[0-9]*:../../x11/xf86-video-savage
DEPENDS+=	xf86-video-siliconmotion-[0-9]*:../../x11/xf86-video-siliconmotion
DEPENDS+=	xf86-video-sis-[0-9]*:../../x11/xf86-video-sis
DEPENDS+=	xf86-video-suncg14-[0-9]*:../../x11/xf86-video-suncg14
DEPENDS+=	xf86-video-suncg3-[0-9]*:../../x11/xf86-video-suncg3
DEPENDS+=	xf86-video-suncg6-[0-9]*:../../x11/xf86-video-suncg6
DEPENDS+=	xf86-video-sunffb-[0-9]*:../../x11/xf86-video-sunffb
DEPENDS+=	xf86-video-sunleo-[0-9]*:../../x11/xf86-video-sunleo
DEPENDS+=	xf86-video-suntcx-[0-9]*:../../x11/xf86-video-suntcx
DEPENDS+=	xf86-video-tdfx-[0-9]*:../../x11/xf86-video-tdfx
DEPENDS+=	xf86-video-tga-[0-9]*:../../x11/xf86-video-tga
DEPENDS+=	xf86-video-trident-[0-9]*:../../x11/xf86-video-trident
DEPENDS+=	xf86-video-tseng-[0-9]*:../../x11/xf86-video-tseng
DEPENDS+=	xf86-video-vesa-[0-9]*:../../x11/xf86-video-vesa
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
DEPENDS+=	xf86-video-vmware-[0-9]*:../../x11/xf86-video-vmware
DEPENDS+=	xf86-video-voodoo-[0-9]*:../../x11/xf86-video-voodoo
.endif
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD"
DEPENDS+=	xf86-video-wsfb-[0-9]*:../../x11/xf86-video-wsfb
.endif
DEPENDS+=	xf86-video-xgi-[0-9]*:../../x11/xf86-video-xgi

.include "../../mk/bsd.pkg.mk"
