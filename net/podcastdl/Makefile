# $NetBSD: Makefile,v 1.33 2024/11/01 12:54:00 wiz Exp $
#

DISTNAME=	podcastdl-0.3.3
PKGREVISION=	16
CATEGORIES=	net
MASTER_SITES=	http://files.bebik.net/podcastdl/ \
		http://rodrigo.osorio.free.fr/freebsd/distfiles/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.bebik.net/doku.php?id=software:podcastdl
COMMENT=	CLI podcast client
LICENSE=	isc

USE_CMAKE=	yes

USE_LANGUAGES=	c c++

.include "../../www/libmrss/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
