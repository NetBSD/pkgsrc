# $NetBSD: Makefile,v 1.33 2020/03/20 11:57:45 nia Exp $
#

DISTNAME=		xblast-2.10.4
PKGREVISION=		1
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
LICENSE=		gnu-gpl-v2 # or later

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-sound
CONFIGURE_ARGS+=	--enable-SMPF
CONFIGURE_ARGS+=	--with-otherdatadir=${PREFIX}/share/xblast

PKG_OPTIONS_VAR=	PKG_OPTIONS.xblast
PKG_SUPPORTED_OPTIONS=	xblast-mini

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mxblast-mini)
# Use a 480x392 window instead of the default 960x784 window
CONFIGURE_ARGS+=	--enable-mini
.endif

SUBST_CLASSES+=		ossaudio
SUBST_STAGE.ossaudio=	pre-configure
SUBST_MESSAGE.ossaudio=	Linking ossaudio library
SUBST_FILES.ossaudio=	Makefile.in
SUBST_SED.ossaudio=	-e 's|xbsndsrv_LDADD =|& ${LIBOSSAUDIO}|'

SUBST_CLASSES+=		xbsndsrv
SUBST_STAGE.xbsndsrv=	pre-configure
SUBST_MESSAGE.xbsndsrv=	Qualify path to xbsndsrv
SUBST_FILES.xbsndsrv=	x11_sound.c
SUBST_SED.xbsndsrv=	-e 's|"xbsndsrv"|"${PREFIX}/bin/xbsndsrv"|'

INSTALLATION_DIRS=	${PKGMANDIR}/man6

post-extract:
	${MV} ${WRKDIR}/levels-2005-01-06/reconstruct?on2.xal \
	      ${WRKDIR}/levels-2005-01-06/reconstruction2.xal

pre-build:
	${MV} ${WRKDIR}/images-2005-01-06 ${WRKSRC}/image
	${MV} ${WRKDIR}/levels-2005-01-06 ${WRKSRC}/level
	${MV} ${WRKDIR}/models-2005-01-06 ${WRKSRC}/image/sprite
	${MV} ${WRKDIR}/sounds ${WRKSRC}/sounds
	${MV} ${WRKDIR}/musics-2005-01-06/* ${WRKSRC}/sounds

post-install:
	${INSTALL_MAN} ${WRKSRC}/xblast.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/xblast.6

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
