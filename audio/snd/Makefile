# $NetBSD: Makefile,v 1.28 2002/09/21 01:02:04 jlam Exp $
#

DISTNAME=		snd
PKGNAME=		snd-19980212
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://ccrma-www.stanford.edu/CCRMA/Software/snd/snd.html
COMMENT=		X based sound editor

NO_SRC_ON_FTP=		Already on MASTER_SITE_LOCAL

USE_BUILDLINK2=		YES
USE_X11BASE=		YES

WRKSRC=			${WRKDIR}
MAKEFILE=		makefile.netbsd
ALL_TARGET=		snd

HTMLDIR=		${PREFIX}/share/doc/html/snd

do-install:
	cd ${WRKSRC} ; ${INSTALL_PROGRAM} snd ${PREFIX}/bin
	cd ${WRKSRC} ; ${INSTALL_DATA} Snd.ad ${PREFIX}/lib/X11/app-defaults/Snd
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC} ; ${INSTALL_DATA} *.gif *.html *.txt README.Snd ${HTMLDIR}

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/motif.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
