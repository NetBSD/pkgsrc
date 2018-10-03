# $NetBSD: Makefile,v 1.3 2018/10/03 22:27:05 nia Exp $

DISTNAME=	miniupnpc-2.1
CATEGORIES=	net
MASTER_SITES=	http://miniupnp.free.fr/files/download.php?file=

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://miniupnp.free.fr/
COMMENT=	Client and library for UPnP IGD services
LICENSE=	modified-bsd

USE_TOOLS+=	gmake
USE_LANGUAGES=	c99

CPPFLAGS.SunOS+=	-D__EXTENSIONS__

.include "../../mk/bsd.pkg.mk"
