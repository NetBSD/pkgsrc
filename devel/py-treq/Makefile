# $NetBSD: Makefile,v 1.7 2022/02/14 09:16:33 wiz Exp $

DISTNAME=	treq-22.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel www python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/treq/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/twisted/treq
COMMENT=	HTTP library for Twisted
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-attrs-[0-9]*:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-incremental-[0-9]*:../../devel/py-incremental
DEPENDS+=	${PYPKGPREFIX}-requests>=2.1.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
