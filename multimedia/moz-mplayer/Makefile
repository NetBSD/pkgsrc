# $NetBSD: Makefile,v 1.2 2004/04/05 18:41:14 wiz Exp $
#

DISTNAME=	mplayerplug-in-1.0
PKGNAME=	moz-mplayer-1.0
PKGREVISION=	1
CATEGORIES=	multimedia www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mplayerplug-in/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://mplayerplug-in.sourceforge.net/
COMMENT=	Embedded video player for Mozilla

DEPENDS+=	mplayer>=0.92:../../multimedia/mplayer

WRKSRC=         ${WRKDIR}/mplayerplug-in
USE_BUILDLINK2=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES

MOZ_PLUGDIR=    ${PREFIX}/lib/mozilla/plugins

do-install:
	${INSTALL_DATA_DIR} ${MOZ_PLUGDIR}
	${INSTALL_DATA} ${WRKSRC}/mplayerplug-in.so ${MOZ_PLUGDIR}

.include "../../mk/bsd.pkg.mk"
