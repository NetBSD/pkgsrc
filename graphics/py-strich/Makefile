# $NetBSD: Makefile,v 1.7 2024/11/07 10:42:40 adam Exp $

DISTNAME=	pystrich-0.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyStrich/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mmulqueen/pyStrich
COMMENT=	1D and 2D barcode generator
LICENSE=	2-clause-bsd AND apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core-[0-9]*:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-Pillow>=10.3:../../graphics/py-Pillow
TEST_DEPENDS+=	dmtx-utils-[0-9]*:../../graphics/dmtx-utils

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
