# $NetBSD: Makefile,v 1.24 2007/01/07 09:13:55 rillig Exp $
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

pre-build:
	${MV} ${WRKDIR}/images-2005-01-06 ${WRKSRC}/image
	${MV} ${WRKDIR}/levels-2005-01-06 ${WRKSRC}/level
	${MV} ${WRKDIR}/models-2005-01-06 ${WRKSRC}/image/sprite
	${MV} ${WRKDIR}/sounds ${WRKSRC}/sounds
	${MV} ${WRKDIR}/musics-2005-01-06/* ${WRKSRC}/sounds

post-install:
	${INSTALL_MAN} ${WRKSRC}/xblast.man ${PREFIX}/${PKGMANDIR}/man6/xblast.6

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
