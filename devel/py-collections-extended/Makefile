# $NetBSD: Makefile,v 1.2 2022/06/18 17:05:00 adam Exp $

DISTNAME=	collections-extended-2.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/collections-extended/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mlenzen/collections-extended
COMMENT=	Python Collections (Bag, setlist, IndexedDict, etc.)
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
