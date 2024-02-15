# $NetBSD: Makefile,v 1.9 2024/02/15 21:45:02 wiz Exp $

DISTNAME=	dnaio-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dnaio/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/marcelm/dnaio
COMMENT=	Read and write FASTQ and FASTA files
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=0.29.20:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-xopen>=1.4.0:../../devel/py-xopen

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
