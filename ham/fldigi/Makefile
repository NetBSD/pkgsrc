# $NetBSD: Makefile,v 1.16 2012/09/28 03:25:41 dholland Exp $
#

DISTNAME=	fldigi-3.03
PKGREVISION=	6
CATEGORIES=	ham
MASTER_SITES=	http://www.w1hkj.com/downloads/fldigi/
LICENSE=	gnu-gpl-v3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.w1hkj.com/Fldigi.html
#HOMEPAGE=	http://lists.berlios.de/mailman/listinfo/fldigi-devel
COMMENT=	Digital radio modem

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-xmlrpc=no
CONFIGURE_ENV+=		STRIP=${STRIP}

.include "../../mk/bsd.prefs.mk"

.if ${LOWER_OPSYS} == "netbsd"
CONFIGURE_ENV+=		ac_cv_header_execinfo_h=no
.endif

.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/portaudio-devel/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../ham/hamlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
