# $NetBSD: Makefile,v 1.14 2002/10/21 11:55:43 wiz Exp $
#

DISTNAME=	crossfire-client-1.0.0
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.ifi.uio.no/pub/crossfire/
DISTFILES=	${CF_SRC} ${CF_SND} ${CF_RAW}

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://crossfire.real-time.com/
COMMENT=	Client for X11 game similar to gauntlet and nethack

DEPENDS+=	gtk+>=1.2.4:../../x11/gtk
DEPENDS+=	png>=1.2.1:../../graphics/png

EXTRACT_ONLY=	${CF_SRC}

CF_SRC=		crossfire-client-1.0.0.tar.gz
CF_SND=		client-0.95.2-au-sounds.tgz
CF_RAW=		client-0.95.2-raw-sounds.tgz

USE_BUILDLINK2=	yes
USE_PERL5=	yes
USE_X11=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
SCRIPTS_ENV+=	${SCRIPTSDIR}
CONFIGURE_ARGS+=	--with-includes=-I${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-sound-dir=${LOCALBASE}/share/cfclient/sounds

REPLACE_PERL=	utils/deftoheader.pl items.pl

pre-build:
	cd ${WRKSRC} && ${MAKE} soundsdef.h

post-install:
	@${INSTALL_DATA_DIR} ${LOCALBASE}/share/cfclient
	cd ${LOCALBASE}/share/cfclient && \
	    ${GZCAT} ${DISTDIR}/${CF_SND} | ${GTAR} xmf -
	cd ${LOCALBASE}/share/cfclient && \
	    ${GZCAT} ${DISTDIR}/${CF_RAW} | ${GTAR} xmf -
	${INSTALL_DATA} ${WRKSRC}/def_keys ${LOCALBASE}/share/cfclient
	@${CHOWN} -R ${ROOT_USER}:games ${LOCALBASE}/share/cfclient

.include "../../graphics/xpm/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
