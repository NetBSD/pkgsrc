# $NetBSD: Makefile,v 1.20 2020/03/08 16:50:58 wiz Exp $
#

DISTNAME=	podcastdl-0.3.3
PKGREVISION=	3
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
