# $NetBSD: Makefile,v 1.1 2023/07/18 15:46:27 adam Exp $

DISTNAME=	icecream-2.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/icecream/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gruns/icecream
COMMENT=	Never use print() to debug again
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-asttokens>=2.0.1:../../lang/py-asttokens
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.3.9:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-executing>=0.3.1:../../lang/py-executing
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.2.0:../../textproc/py-pygments
#TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.2.4:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
