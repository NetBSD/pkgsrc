# $NetBSD: Makefile,v 1.3 2003/05/05 19:05:14 jmmv Exp $
#

DISTNAME=	mplayerplug-in_v0.71
PKGNAME=	moz-mplayer-0.71
PKGREVISION=	1
WRKSRC=         ${WRKDIR}/mplayerplug-in
CATEGORIES=	graphics www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mplayerplug-in/}

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://mplayerplug-in.sourceforge.net/
COMMENT=	Embedded video player for Mozilla

DEPENDS+=	mplayer>=0.90rc14:../../graphics/mplayer
DEPENDS+=	mozilla-[0-9]*:../../www/mozilla

USE_BUILDLINK2=	YES
USE_X11BASE=	YES

MOZ_PLUGDIR=    ${PREFIX}/lib/mozilla/plugins

do-install:
	${INSTALL_DATA_DIR} ${MOZ_PLUGDIR}
	${INSTALL_DATA} ${WRKSRC}/mplayerplug-in.so ${MOZ_PLUGDIR}

.include "../../mk/bsd.pkg.mk"
