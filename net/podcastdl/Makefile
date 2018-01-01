# $NetBSD: Makefile,v 1.10 2018/01/01 21:18:49 adam Exp $
#

DISTNAME=	podcastdl-0.3.0
PKGREVISION=	9
CATEGORIES=	net
MASTER_SITES=	http://files.bebik.net/podcastdl/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.bebik.net/doku.php?id=software:podcastdl
COMMENT=	Podcastdl is a CLI podcast client
LICENSE=	isc

USE_CMAKE=	yes

USE_LANGUAGES=	c c++

.include "../../www/libmrss/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
