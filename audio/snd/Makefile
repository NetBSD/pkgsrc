# $NetBSD: Makefile,v 1.3 1998/04/15 10:38:11 agc Exp $
#

DISTNAME=		snd
PKGNAME=		snd-19980212
NO_WRKSUBDIR=		YES
CATEGORIES=		audio
MASTER_SITES=		ftp://ccrma-ftp.stanford.edu/pub/Lisp/

MAINTAINER=		hubertf@netbsd.org

LIB_DEPENDS=		Xpm.4.:${PORTSDIR}/graphics/xpm \
			Xm.0.:${PORTSDIR}/x11/lesstif

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
