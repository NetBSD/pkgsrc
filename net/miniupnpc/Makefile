# $NetBSD: Makefile,v 1.9 2023/05/03 20:13:17 nikita Exp $

DISTNAME=	miniupnpc-2.2.4
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
