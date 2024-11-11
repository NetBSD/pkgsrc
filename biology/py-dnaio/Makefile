# $NetBSD: Makefile,v 1.11 2024/11/11 07:27:53 wiz Exp $

DISTNAME=	dnaio-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dnaio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/marcelm/dnaio
COMMENT=	Read and write FASTQ and FASTA files
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=0.29.20:../../devel/py-cython
DEPENDS+=	${PYPKGPREFIX}-xopen>=1.4.0:../../devel/py-xopen

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
