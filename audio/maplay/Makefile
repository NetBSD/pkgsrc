# $NetBSD: Makefile,v 1.8 2001/09/09 20:36:12 agc Exp $
# FreeBSD Id: Makefile,v 1.6 1997/01/07 14:58:04 torstenb Exp 
#

DISTNAME=       maplay1_2
PKGNAME=	maplay-1.2
CATEGORIES=	audio
MASTER_SITES=   http://www.iuma.com/IUMA/ftp/audio_utils/mpeg_players/Workstations/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org
COMMENT=	MPEG audio player/decoder for layer I and II MPEG audio streams

WRKSRC=		${WRKDIR}
PATCH_STRIP=	-p2

pre-configure:
	@(cd ${WRKSRC}; ${MAKE} pre-install)

.include "../../mk/bsd.pkg.mk"
