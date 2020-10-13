# $NetBSD: Makefile,v 1.3 2020/10/13 11:10:49 adam Exp $

DISTNAME=	sniffio-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sniffio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-trio/sniffio
COMMENT=	Sniff out which async library your code is running under
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 36
DEPENDS+=	${PYPKGPREFIX}-contextvars>=2.1:../../devel/py-contextvars
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
