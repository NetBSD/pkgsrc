# $NetBSD: Makefile,v 1.49 2023/11/12 13:21:53 wiz Exp $
#

DISTNAME=		cqcam-0.91
PKGREVISION=		12
CATEGORIES=		graphics x11
MASTER_SITES=		http://piki.org/patrick/cqcam/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://piki.org/patrick/cqcam/
COMMENT=		Free Color QuickCam control program

.include "../../mk/bsd.prefs.mk"

# Tries to install a device driver with unrestricted access to all
# hardware ports, which is also specific to i86pc platforms.
OPSYSVARS+=			NOT_FOR_UNPRIVILEGED
NOT_FOR_UNPRIVILEGED.SunOS=	yes

.if ${MACHINE_ARCH} != "i386"
CONFIGURE_ARGS+=	--disable-asm
.endif

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-xview
USE_LANGUAGES=		c c++

CONFIGURE_ENV+=		TCLCONFIG_SH=${TCLCONFIG_SH:Q}
CONFIGURE_ARGS+=	--x-includes=${X11BASE}/include
CONFIGURE_ARGS+=	--x-libraries=${X11BASE}/lib

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../mk/jpeg.buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
