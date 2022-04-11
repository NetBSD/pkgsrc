# $NetBSD: Makefile,v 1.8 2022/04/11 10:04:38 nikita Exp $

DISTNAME=	miniupnpc-2.2.3
CATEGORIES=	net
MASTER_SITES=	http://miniupnp.free.fr/files/download.php?file=

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://miniupnp.free.fr/
COMMENT=	Client and library for UPnP IGD services
LICENSE=	modified-bsd

USE_TOOLS+=	gmake
USE_LANGUAGES=	c99

CPPFLAGS.SunOS+=	-D__EXTENSIONS__
LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../mk/bsd.pkg.mk"
