# $NetBSD: Makefile,v 1.24 2021/09/29 19:01:10 adam Exp $
#

DISTNAME=	podcastdl-0.3.3
PKGREVISION=	7
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
