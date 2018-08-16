# $NetBSD: Makefile,v 1.12 2018/08/16 18:55:08 adam Exp $
#

DISTNAME=	podcastdl-0.3.0
PKGREVISION=	11
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
