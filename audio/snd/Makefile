# $NetBSD: Makefile,v 1.7 1998/05/08 23:05:24 hubertf Exp $
#

DISTNAME=		snd
PKGNAME=		snd-19980212
NO_WRKSUBDIR=		YES
CATEGORIES=		audio
MASTER_SITES=		ftp://ccrma-ftp.stanford.edu/pub/Lisp/

MAINTAINER=		hubertf@netbsd.org

DEPENDS+=		xpm-3.4j:../../graphics/xpm
BUILD_DEPENDS+=		${X11BASE}/include/Xm:../../x11/lesstif

USE_X11=		YES
REQUIRES_MOTIF=		YES
MAKEFILE=		makefile.netbsd
ALL_TARGET=		snd

do-install:
	cd ${WRKSRC} ; ${INSTALL_PROGRAM} snd ${PREFIX}/bin
	cd ${WRKSRC} ; ${INSTALL_DATA} Snd.ad ${PREFIX}/lib/X11/app-defaults/Snd
	${MKDIR} ${PREFIX}/share/doc/snd
	cd ${WRKSRC} ; ${INSTALL_DATA} *.gif *.html *.txt README.Snd ${PREFIX}/share/doc/snd

.include "../../mk/bsd.pkg.mk"
