# $NetBSD: Makefile,v 1.5 1999/03/08 10:53:55 agc Exp $
# FreeBSD Id: Makefile,v 1.6 1997/01/07 14:58:04 torstenb Exp 
#

DISTNAME=       maplay1_2
PKGNAME=	maplay-1.2
CATEGORIES=	audio
MASTER_SITES=   ftp://ftp.iuma.com/audio_utils/mpeg_players/Workstations/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org

NO_WRKSUBDIR=	yes
PATCH_STRIP=	-p2

pre-configure:
	@(cd ${WRKSRC}; ${MAKE} pre-install)

.include "../../mk/bsd.pkg.mk"
