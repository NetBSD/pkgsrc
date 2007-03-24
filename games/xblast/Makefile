# $NetBSD: Makefile,v 1.26 2007/03/24 19:21:24 joerg Exp $
#

DISTNAME=		xblast-2.10.2
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xblast/}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			images-2005-01-06${EXTRACT_SUFX} \
			levels-2005-01-06${EXTRACT_SUFX} \
			models-2005-01-06${EXTRACT_SUFX} \
			musics-2005-01-06${EXTRACT_SUFX} \
			sounds${EXTRACT_SUFX}

MAINTAINER=		dsainty@NetBSD.org
HOMEPAGE=		http://xblast.sourceforge.net/
COMMENT=		2-6 player kill the other guy with bombs game. A real blast!

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-sound
CONFIGURE_ARGS+=	--enable-SMPF
CONFIGURE_ARGS+=	--with-otherdatadir=${PREFIX}/share/xblast

SUBST_CLASSES+=		ossaudio
SUBST_STAGE.ossaudio=	pre-configure
SUBST_MESSAGE.ossaudio=	"Linking ossaudio library"
SUBST_FILES.ossaudio=	Makefile.in
SUBST_SED.ossaudio=-e 's|xbsndsrv_LDFLAGS =|xbsndsrv_LDFLAGS = ${LIBOSSAUDIO}|'

INSTALLATION_DIRS=	${PKGMANDIR}/man6

pre-build:
	${MV} ${WRKDIR}/images-2005-01-06 ${WRKSRC}/image
	${MV} ${WRKDIR}/levels-2005-01-06 ${WRKSRC}/level
	${MV} ${WRKDIR}/models-2005-01-06 ${WRKSRC}/image/sprite
	${MV} ${WRKDIR}/sounds ${WRKSRC}/sounds
	${MV} ${WRKDIR}/musics-2005-01-06/* ${WRKSRC}/sounds

post-install:
	${INSTALL_MAN} ${WRKSRC}/xblast.man ${PREFIX}/${PKGMANDIR}/man6/xblast.6

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
