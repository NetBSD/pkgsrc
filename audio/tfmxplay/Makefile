# $NetBSD: Makefile,v 1.12 2006/03/09 21:04:41 jlam Exp $
#

DISTNAME=	tfmxplay-0.6
CATEGORIES=	audio
MASTER_SITES=	http://darkstar.tabu.uni-bonn.de/~neo/tfmx/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://darkstar.tabu.uni-bonn.de/~neo/audio.html
COMMENT=	Console TFMX (amiga games sound file format) player

NOT_FOR_PLATFORM=	Interix-*-*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tfmx-play ${PREFIX}/bin/tfmxplay
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tfmxplay
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/tfmxplay/

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
