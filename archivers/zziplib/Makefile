# $NetBSD: Makefile,v 1.27 2021/01/11 22:41:56 wiz Exp $

DISTNAME=	zziplib-0.13.72
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=gdraheim/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gdraheim/zziplib
COMMENT=	Library for ZIP archive handling
LICENSE=	gnu-lgpl-v2 OR mpl-1.1

BUILD_DEPENDS+=	zip-[0-9]*:../../archivers/zip
BUILD_DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

USE_CMAKE=	yes
USE_TOOLS+=	bash:build

CMAKE_ARGS+=	-DZZIPTEST=NO

CHECK_PORTABILITY_SKIP+=	old.configure

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
