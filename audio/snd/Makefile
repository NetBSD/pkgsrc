# $NetBSD: Makefile,v 1.9 1998/05/11 11:34:05 frueauf Exp $
#

DISTNAME=		snd
PKGNAME=		snd-19980212
NO_WRKSUBDIR=		YES
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		hubertf@netbsd.org

DEPENDS+=		xpm-3.4j:../../graphics/xpm

USE_X11=		YES
REQUIRES_MOTIF=		YES
MAKEFILE=		makefile.netbsd
ALL_TARGET=		snd

post-patch:
	${MV} ${WRKSRC}/makefile.netbsd ${WRKSRC}/makefile.netbsd.bak
	${CAT} ${WRKSRC}/makefile.netbsd.bak | \
		${SED} s/@LOCALBASE@/${LOCALBASE:S/\//\\\\\//g}/g | \
		${SED} s/@X11BASE@/${X11BASE:S/\//\\\\\//g}/g \
		> ${WRKSRC}/makefile.netbsd

do-install:
	cd ${WRKSRC} ; ${INSTALL_PROGRAM} snd ${PREFIX}/bin
	cd ${WRKSRC} ; ${INSTALL_DATA} Snd.ad ${PREFIX}/lib/X11/app-defaults/Snd
	${MKDIR} ${PREFIX}/share/doc/snd
	cd ${WRKSRC} ; ${INSTALL_DATA} *.gif *.html *.txt README.Snd ${PREFIX}/share/doc/snd

.include "../../mk/bsd.pkg.mk"
