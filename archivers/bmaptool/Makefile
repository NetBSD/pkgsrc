# $NetBSD: Makefile,v 1.1 2026/08/12 08:12:24 adam Exp $

DISTNAME=	bmaptool-3.9.0
CATEGORIES=	archivers sysutils python
MASTER_SITES=	${MASTER_SITE_GITHUB:=yoctoproject/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yoctoproject/bmaptool
COMMENT=	Block map tools
LICENSE=	gnu-gpl-v2

CONFLICTS+=	bmap-tools-[0-9]*
SUPERSEDES=	bmap-tools-[0-9]*

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling

USE_LANGUAGES=	# none

# as of 3.9.0
# 4 failed, 10 passed, 8 skipped

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
