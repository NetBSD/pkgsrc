# $NetBSD: Makefile,v 1.16 2026/10/16 19:43:41 adam Exp $

DISTNAME=	dnaio-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dnaio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/marcelm/dnaio
COMMENT=	Read and write FASTQ and FASTA files
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=0.29.20:../../devel/py-cython
DEPENDS+=	${PYPKGPREFIX}-xopen>=1.4.0:../../devel/py-xopen

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
