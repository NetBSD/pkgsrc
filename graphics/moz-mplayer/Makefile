# $NetBSD: Makefile,v 1.4 2003/05/23 09:37:27 salo Exp $
#

DISTNAME=	mplayerplug-in-0.80
PKGNAME=	moz-mplayer-0.80
WRKSRC=         ${WRKDIR}/mplayerplug-in
CATEGORIES=	graphics www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mplayerplug-in/}

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://mplayerplug-in.sourceforge.net/
COMMENT=	Embedded video player for Mozilla

DEPENDS+=	mplayer>=0.90rc14:../../graphics/mplayer
DEPENDS+=	mozilla-[0-9]*:../../www/mozilla

USE_BUILDLINK2=	YES
USE_X11=	YES

MOZ_PLUGDIR=    ${PREFIX}/lib/mozilla/plugins

do-install:
	${INSTALL_DATA_DIR} ${MOZ_PLUGDIR}
	${INSTALL_DATA} ${WRKSRC}/mplayerplug-in.so ${MOZ_PLUGDIR}

.include "../../mk/bsd.pkg.mk"
