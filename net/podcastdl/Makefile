# $NetBSD: Makefile,v 1.39 2026/01/07 08:48:25 wiz Exp $
#

DISTNAME=	podcastdl-0.3.3
PKGREVISION=	21
CATEGORIES=	net
MASTER_SITES=	http://files.bebik.net/podcastdl/ \
		http://rodrigo.osorio.free.fr/freebsd/distfiles/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.bebik.net/doku.php?id=software:podcastdl
COMMENT=	CLI podcast client
LICENSE=	isc

USE_CMAKE=	yes

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

USE_LANGUAGES=	c c++

.include "../../www/libmrss/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
