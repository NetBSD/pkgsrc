# $NetBSD: Makefile,v 1.16 2000/08/18 22:46:30 hubertf Exp $
#

DISTNAME=		snd
PKGNAME=		snd-19980212
NO_WRKSUBDIR=		YES
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://ccrma-www.stanford.edu/CCRMA/Software/snd/snd.html

DEPENDS+=		xpm-3.4k:../../graphics/xpm

NO_SRC_ON_FTP=		Already on MASTER_SITE_LOCAL

USE_MOTIF=		yes
MAKEFILE=		makefile.netbsd
ALL_TARGET=		snd

do-install:
	cd ${WRKSRC} ; ${INSTALL_PROGRAM} snd ${PREFIX}/bin
	cd ${WRKSRC} ; ${INSTALL_DATA} Snd.ad ${PREFIX}/lib/X11/app-defaults/Snd
	${MKDIR} ${PREFIX}/share/doc/snd
	cd ${WRKSRC} ; ${INSTALL_DATA} *.gif *.html *.txt README.Snd ${PREFIX}/share/doc/snd

.include "../../mk/bsd.pkg.mk"
