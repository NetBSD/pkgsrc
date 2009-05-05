# $NetBSD: Makefile,v 1.14 2009/05/05 18:47:53 zafer Exp $
#

DISTNAME=	tfmxplay-0.6
CATEGORIES=	audio
MASTER_SITES=	# http://darkstar.tabu.uni-bonn.de/~neo/tfmx/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://darkstar.tabu.uni-bonn.de/~neo/audio.html
COMMENT=	Console TFMX (amiga games sound file format) player

NOT_FOR_PLATFORM=	Interix-*-*

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tfmx-play ${DESTDIR}${PREFIX}/bin/tfmxplay
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/tfmxplay
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/tfmxplay

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
