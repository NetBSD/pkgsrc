# $NetBSD: Makefile,v 1.1 2020/01/08 20:04:27 adam Exp $

DISTNAME=	sniffio-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sniffio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-trio/sniffio
COMMENT=	Sniff out which async library your code is running under
LICENSE=	mit

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 36
DEPENDS+=	${PYPKGPREFIX}-contextvars>=2.1:../../devel/py-contextvars
.endif

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
