# $NetBSD: Makefile,v 1.11 1998/06/09 13:36:48 agc Exp $
#

DISTNAME=		snd
PKGNAME=		snd-19980212
NO_WRKSUBDIR=		YES
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		hubertf@netbsd.org

DEPENDS+=		xpm-3.4j:../../graphics/xpm

USE_X11=		yes
USE_MOTIF=		yes
MAKEFILE=		makefile.netbsd
ALL_TARGET=		snd

do-install:
	cd ${WRKSRC} ; ${INSTALL_PROGRAM} snd ${PREFIX}/bin
	cd ${WRKSRC} ; ${INSTALL_DATA} Snd.ad ${PREFIX}/lib/X11/app-defaults/Snd
	${MKDIR} ${PREFIX}/share/doc/snd
	cd ${WRKSRC} ; ${INSTALL_DATA} *.gif *.html *.txt README.Snd ${PREFIX}/share/doc/snd

.include "../../mk/bsd.pkg.mk"
