# $NetBSD: Makefile,v 1.35 2004/12/03 15:14:51 wiz Exp $
#

DISTNAME=		snd
PKGNAME=		snd-19980212
PKGREVISION=		2
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		hubertf@NetBSD.org
HOMEPAGE=		http://ccrma-www.stanford.edu/CCRMA/Software/snd/snd.html
COMMENT=		X based sound editor

NO_SRC_ON_FTP=		Already on MASTER_SITE_LOCAL

WRKSRC=			${WRKDIR}
USE_BUILDLINK3=		YES
USE_X11=		YES

MAKEFILE=		makefile.netbsd
BUILD_TARGET=		snd

HTMLDIR=		${PREFIX}/share/doc/html/snd

do-install:
	cd ${WRKSRC} ; ${INSTALL_PROGRAM} snd ${PREFIX}/bin
	cd ${WRKSRC} ; ${INSTALL_DATA} Snd.ad ${PREFIX}/lib/X11/app-defaults/Snd
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC} ; ${INSTALL_DATA} *.gif *.html *.txt README.Snd ${HTMLDIR}

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
