# $NetBSD: Makefile,v 1.1.1.1 2008/10/23 08:07:09 wulf Exp $
#

DISTNAME=	fldigi-3.03
CATEGORIES=	ham
MASTER_SITES=	http://www.w1hkj.com/fldigi-distro/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://www.w1hkj.com/Fldigi.html
COMMENT=	Digital radio modem

USE_DIRS+=	xdg-1.1
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/portaudio-devel/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../ham/hamlib/buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
