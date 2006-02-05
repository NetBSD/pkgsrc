# $NetBSD: Makefile,v 1.27 2006/02/05 23:09:13 joerg Exp $
#

DISTNAME=	crossfire-client-1.0.0
PKGREVISION=	6
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.ifi.uio.no/pub/crossfire/
DISTFILES=	${CF_SRC} ${CF_SND} ${CF_RAW}

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://crossfire.real-time.com/
COMMENT=	Client for X11 game similar to gauntlet and nethack

EXTRACT_ONLY=	${CF_SRC}

CF_SRC=		crossfire-client-1.0.0.tar.gz
CF_SND=		client-0.95.2-au-sounds.tgz
CF_RAW=		client-0.95.2-raw-sounds.tgz

USE_TOOLS+=	gmake gtar perl:run
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-sound-dir=${PREFIX}/share/cfclient/sounds

REPLACE_PERL=	utils/deftoheader.pl items.pl

SUBST_CLASSES+=		dsp
SUBST_STAGE.dsp=	post-patch
SUBST_MESSAGE.dsp=	Adjusting path to sound device.
SUBST_FILES.dsp=	cfsndserv.c
SUBST_SED.dsp=		-e "s|/dev/dsp|${DEVOSSAUDIO}|"

pre-build:
	cd ${WRKSRC} && ${MAKE} soundsdef.h

post-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/share/cfclient
	cd ${PREFIX}/share/cfclient && \
	    ${GZCAT} ${DISTDIR}/${CF_SND} | ${GTAR} xmf -
	cd ${PREFIX}/share/cfclient && \
	    ${GZCAT} ${DISTDIR}/${CF_RAW} | ${GTAR} xmf -
	${INSTALL_DATA} ${WRKSRC}/def_keys ${PREFIX}/share/cfclient
	@${CHOWN} -R ${ROOT_USER}:games ${PREFIX}/share/cfclient

.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
