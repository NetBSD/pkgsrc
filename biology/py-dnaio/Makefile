# $NetBSD: Makefile,v 1.4 2021/05/21 11:38:13 adam Exp $

DISTNAME=	dnaio-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dnaio/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/marcelm/dnaio
COMMENT=	Read and write FASTQ and FASTA files
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-xopen>=0.8.2:../../devel/py-xopen

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
