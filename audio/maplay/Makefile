# $NetBSD: Makefile,v 1.10 2003/05/06 17:40:26 jmmv Exp $
# FreeBSD Id: Makefile,v 1.6 1997/01/07 14:58:04 torstenb Exp
#

DISTNAME=       maplay1_2
PKGNAME=	maplay-1.2
WRKSRC=		${WRKDIR}
CATEGORIES=	audio
MASTER_SITES=   http://www.iuma.com/IUMA/ftp/audio_utils/mpeg_players/Workstations/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org
COMMENT=	MPEG audio player/decoder for layer I and II MPEG audio streams

PATCH_STRIP=	-p2

pre-configure:
	@(cd ${WRKSRC}; ${MAKE} pre-install)

.include "../../mk/bsd.pkg.mk"
