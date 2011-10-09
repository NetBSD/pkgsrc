# $NetBSD: Makefile,v 1.21.8.1 2011/10/09 13:26:47 tron Exp $
#

DISTNAME=	xtel-3.3.0
PKGREVISION=	12
CATEGORIES=	comms x11
MASTER_SITES=	http://pficheux.free.fr/xtel/download/

PATCHFILES=	xtel-jumbo-patch-20111008.gz
PATCH_SITES=	http://www.NetBSD.org/~dholland/patchkits/xtel/
PATCH_DIST_STRIP= -p1

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://pficheux.free.fr/xtel/
COMMENT=	Minitel(r) emulator

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=	no

USE_IMAKE=	YES
USE_TOOLS+=	mkfontdir bdftopcf

FONTDIR=	${PREFIX}/lib/X11/fonts
FONTS_DIRS.x11=	${FONTDIR}/xtel
REQD_DIRS=	${FONTDIR}/xtel

SUBST_CLASSES+=		fontdir
SUBST_STAGE.fontdir=	post-configure
SUBST_MESSAGE.fontdir=	Fixing imake font directory.
SUBST_FILES.fontdir=	fonts/Makefile
SUBST_SED.fontdir=	's,^[^A-Z]*FONTDIR =.*,FONTDIR = '${FONTDIR:Q},

INSTALLATION_DIRS=	share/examples/xtel
INSTALL_MAKE_FLAGS=	PPPDIR=${PREFIX}/share/examples/xtel

SPECIAL_PERMS+=		bin/mdmdetect ${SETUID_ROOT_PERMS}

.include "../../mk/jpeg.buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
