# $NetBSD: Makefile,v 1.1 2022/07/27 18:40:31 rhialto Exp $

DISTNAME=	fastbencode-0.0.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters python
MASTER_SITES+=	${MASTER_SITE_PYPI:=f/fastbencode/}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://github.com/breezy-team/fastbencode
COMMENT=	Implementation of bencode with optional fast C extensions
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
