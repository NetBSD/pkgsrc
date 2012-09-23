# $NetBSD: Makefile,v 1.18 2012/09/23 05:36:23 obache Exp $
#

DISTNAME=	mednafen-0.8.D.3
PKGNAME=	mednafen-0.8.13.3
PKGREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mednafen/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://mednafen.sourceforge.net/
COMMENT=	Portable multi-system emulator
LICENSE=	gnu-gpl-v2

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
SUBST_FILES.dsp=	src/sexyal/drivers/oss.cpp src/sexyal/sexyal.cpp
SUBST_SED.dsp=		-e s,/dev/dsp,${DEVOSSAUDIO},

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "modular"
CONFIGURE_ARGS+=	--x-includes=${PREFIX:Q}/include
CONFIGURE_ARGS+=	--x-libraries=${PREFIX:Q}/lib
.endif

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
