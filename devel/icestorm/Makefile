# $NetBSD: Makefile,v 1.1 2024/02/28 06:02:38 thorpej Exp $

# There are no release tags for icestorm
ICESTORM_VERSION=0.0.20240227

DISTNAME=	icestorm-${ICESTORM_VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=YosysHQ/}
GITHUB_TAG=	1a40ae75d4eebee9cce73a2c4d634fd42ed0110f

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	https://github.com/YosysHQ/icestorm
COMMENT=	Lattice iCE40 FPGAs Bitstream Documentation and tools
LICENSE=	isc

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

REPLACE_PYTHON+= icebox/*.py

INSTALLATION_DIRS=	bin share

.include "../../devel/libftdi/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
