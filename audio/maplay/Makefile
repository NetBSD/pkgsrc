# $NetBSD: Makefile,v 1.15 2004/02/28 23:11:00 recht Exp $
# FreeBSD Id: Makefile,v 1.6 1997/01/07 14:58:04 torstenb Exp
#

DISTNAME=       maplay1_2
PKGNAME=	maplay-1.2
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cs.tu-berlin.de/pub/misc/maplay1.2/
EXTRACT_SUFX=	.tar

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	MPEG audio player/decoder for layer I and II MPEG audio streams

WRKSRC=		${WRKDIR}

pre-configure:
	@(cd ${WRKSRC}; ${MAKE} pre-install)

.include "../../mk/bsd.pkg.mk"
