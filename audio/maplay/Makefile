# $NetBSD: Makefile,v 1.3 1998/04/15 10:38:10 agc Exp $
# FreeBSD Id: Makefile,v 1.6 1997/01/07 14:58:04 torstenb Exp 
#

DISTNAME=       maplay1_2
PKGNAME=	maplay-1.2
CATEGORIES=	audio
MASTER_SITES=   ftp://ftp.iuma.com/audio_utils/mpeg_players/Workstations/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	torstenb@FreeBSD.org

NO_WRKSUBDIR=	yes
PATCH_STRIP=	-p2

pre-configure:
	@(cd ${WRKSRC}; make pre-install)

.include "../../mk/bsd.pkg.mk"
