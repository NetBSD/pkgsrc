# $NetBSD: Makefile,v 1.2 2025/01/14 16:58:59 adam Exp $

DISTNAME=	icecream-2.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/icecream/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gruns/icecream
COMMENT=	Never use print() to debug again
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-asttokens>=2.0.1:../../lang/py-asttokens
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.3.9:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-executing>=2.1.0:../../lang/py-executing
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.2.0:../../textproc/py-pygments

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
