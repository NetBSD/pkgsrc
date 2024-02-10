# $NetBSD: Makefile,v 1.11 2024/02/10 13:12:35 bacon Exp $

DISTNAME=	cutadapt-4.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cutadapt/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://cutadapt.readthedocs.io/en/stable/
COMMENT=	Find and remove adapter sequences, primers, poly-A tails, etc
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
# needed for python 3.11 as of cutadapt 3.5 release
TOOL_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython
DEPENDS+=	${PYPKGPREFIX}-xopen>=1.6.0:../../devel/py-xopen
DEPENDS+=	${PYPKGPREFIX}-dnaio>=0.10.0:../../biology/py-dnaio

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-xopen

USE_PKG_RESOURCES=	yes

PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
