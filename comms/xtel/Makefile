# $NetBSD: Makefile,v 1.22 2011/10/08 07:04:34 dholland Exp $
#

DISTNAME=	xtel-3.3.0
PKGREVISION=	11
CATEGORIES=	comms x11
MASTER_SITES=	http://pficheux.free.fr/xtel/download/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://pficheux.free.fr/xtel/
COMMENT=	Minitel(r) emulator

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=	no

USE_IMAKE=	YES
USE_TOOLS+=	mkfontdir bdftopcf

FONTS_DIRS.x11=	${PREFIX}/lib/X11/fonts/xtel
REQD_DIRS=	${PREFIX}/lib/X11/fonts/xtel

INSTALLATION_DIRS=	share/examples/xtel
INSTALL_MAKE_FLAGS=	PPPDIR=${PREFIX}/share/examples/xtel

SPECIAL_PERMS+=		bin/mdmdetect ${SETUID_ROOT_PERMS}

.include "../../mk/jpeg.buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
