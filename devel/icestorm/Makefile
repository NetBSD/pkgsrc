# $NetBSD: Makefile,v 1.3 2024/03/02 23:07:59 thorpej Exp $

# There are no release tags for icestorm
ICESTORM_VERSION=0.0.20240227

DISTNAME=	icestorm-${ICESTORM_VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=YosysHQ/}
GITHUB_TAG=	1a40ae75d4eebee9cce73a2c4d634fd42ed0110f

PKGREVISION=	1

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	https://github.com/YosysHQ/icestorm
COMMENT=	Lattice iCE40 FPGAs Bitstream Documentation and tools
LICENSE=	isc

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
.if ${OPSYS} == "Darwin"
# The -i option on Darwin sed(1) behaves differently, and textproc/nbsed
# (which gets substituted for the system sed(1) for other reasons) doesn't
# support the -i option.  See also patches/patch-icebox_Makefile.
USE_TOOLS+=	gsed
.endif

REPLACE_PYTHON+= icebox/*.py

INSTALLATION_DIRS=	bin share

.include "../../devel/libftdi/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
