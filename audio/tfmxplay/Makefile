# $NetBSD: Makefile,v 1.4 2003/06/02 01:21:32 jschauma Exp $
#

DISTNAME=	tfmxplay-0.6
CATEGORIES=	audio
MASTER_SITES=	http://darkstar.tabu.uni-bonn.de/~neo/tfmx/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://darkstar.tabu.uni-bonn.de/~neo/audio.html
COMMENT=	console TFMX (amiga games sound file format) player

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tfmx-play ${PREFIX}/bin/tfmxplay
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tfmxplay
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/tfmxplay/

.include "../../mk/bsd.pkg.mk"
