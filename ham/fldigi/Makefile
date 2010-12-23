# $NetBSD: Makefile,v 1.10 2010/12/23 11:44:47 dsainty Exp $
#

DISTNAME=	fldigi-3.03
PKGREVISION=	4
CATEGORIES=	ham
MASTER_SITES=	http://www.w1hkj.com/fldigi-distro/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://www.w1hkj.com/Fldigi.html
COMMENT=	Digital radio modem

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-xmlrpc=no
CONFIGURE_ENV+=		STRIP=${STRIP}

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/portaudio-devel/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../ham/hamlib/buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
