# $NetBSD: Makefile,v 1.1.1.1 2000/12/13 08:19:20 garbled Exp $
#

DISTNAME=	crossfire-client-0.95.8
PKGNAME=	crossfire_client-0.95.8
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.ifi.uio.no/pub/crossfire/
DISTFILES=	${CF_SRC} ${CF_SND}

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://crossfire.real-time.com/

DEPENDS+=	gtk+>=1.2.4:../../x11/gtk
DEPENDS+=	png>=1.0.3:../../graphics/png

EXTRACT_ONLY=	${CF_SRC}

CF_SRC=		crossfire-client-0.95.8.tar.gz
CF_SND=		client-0.95.2-au-sounds.tgz

USE_XPM=	yes
USE_PERL5=	yes
USE_X11=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
SCRIPTS_ENV+=	${SCRIPTSDIR}
CONFIGURE_ARGS+=	--prefix=${LOCALBASE}
CONFIGURE_ARGS+=	--with-includes=-I${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-sound-dir=${LOCALBASE}/share/cfclient/sounds

pre-build:
	cd ${WRKSRC} && ${MAKE} soundsdef.h

post-install:
	@${MKDIR} ${LOCALBASE}/share/cfclient
	cd ${LOCALBASE}/share/cfclient && \
	    ${GZCAT} ${DISTDIR}/${CF_SND} | ${GTAR} xmf -
	@chown -R root:games ${LOCALBASE}/share/cfclient

.include "../../mk/bsd.pkg.mk"
