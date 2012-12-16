# $NetBSD: Makefile,v 1.2 2012/12/16 01:52:30 obache Exp $
#

DISTNAME=	podcastdl-0.3.0
PKGREVISION=	1
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
