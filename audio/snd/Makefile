# $NetBSD: Makefile,v 1.21 2001/06/30 21:14:10 jlam Exp $
#

DISTNAME=		snd
PKGNAME=		snd-19980212
NO_WRKSUBDIR=		YES
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://ccrma-www.stanford.edu/CCRMA/Software/snd/snd.html
COMMENT=		X based sound editor

NO_SRC_ON_FTP=		Already on MASTER_SITE_LOCAL

USE_BUILDLINK_ONLY=	YES
MAKEFILE=		makefile.netbsd
ALL_TARGET=		snd
HTMLDIR=		${PREFIX}/share/doc/html/snd

do-install:
	cd ${WRKSRC} ; ${INSTALL_PROGRAM} snd ${PREFIX}/bin
	cd ${WRKSRC} ; ${INSTALL_DATA} Snd.ad ${PREFIX}/lib/X11/app-defaults/Snd
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC} ; ${INSTALL_DATA} *.gif *.html *.txt README.Snd ${HTMLDIR}

.include "../../graphics/xpm/buildlink.mk"
.include "../../x11/lesstif/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
