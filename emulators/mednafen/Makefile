# $NetBSD: Makefile,v 1.10 2009/02/25 13:16:47 wiz Exp $
#

DISTNAME=	mednafen-0.8.B
PKGNAME=	mednafen-0.8.11
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mednafen/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://mednafen.sourceforge.net/
COMMENT=	Portable multi-system emulator

WRKSRC=			${WRKDIR}/mednafen
GNU_CONFIGURE=		yes
USE_TOOLS+=		intltool pkg-config
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	share/doc/mednafen

SUBST_CLASSES+=		dsp
SUBST_STAGE.dsp=	pre-configure
SUBST_MESSAGE.dsp=	Fixing path to audio device.
SUBST_FILES.dsp=	src/sexyal/drivers/esd.c src/sexyal/drivers/oss.c \
			src/sexyal/drivers/oss.c src/sexyal/sexyal.c
SUBST_SED.dsp=		-e s,/dev/dsp,${DEVOSSAUDIO},

post-install:
	${INSTALL_DATA} ${WRKSRC}/Documentation/*.html \
		${DESTDIR}${PREFIX}/share/doc/mednafen

.include "../../audio/esound/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
