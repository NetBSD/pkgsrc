# $NetBSD: Makefile,v 1.13 2004/01/18 13:59:25 mrauch Exp $
# FreeBSD Id: Makefile,v 1.6 1997/01/07 14:58:04 torstenb Exp
#

DISTNAME=       maplay1_2
PKGNAME=	maplay-1.2
PKGREVISION=	1
WRKSRC=		${WRKDIR}
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cs.tu-berlin.de/pub/misc/maplay1.2/
EXTRACT_SUFX=	.tar

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	MPEG audio player/decoder for layer I and II MPEG audio streams

PATCH_STRIP=	-p2

pre-configure:
	@(cd ${WRKSRC}; ${MAKE} pre-install)

.include "../../mk/bsd.pkg.mk"
