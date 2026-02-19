# $NetBSD: Makefile,v 1.8 2026/02/19 07:11:27 wiz Exp $

DISTNAME=	dna_features_viewer-3.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dna-features-viewer/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/Edinburgh-Genome-Foundry/DnaFeaturesViewer
COMMENT=	Python library to visualize DNA features, e.g. GenBank or Gff files
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-biopython>0:../../biology/py-biopython
DEPENDS+=	${PYPKGPREFIX}-bcbio-gff>0:../../biology/py-bcbio-gff
DEPENDS+=	${PYPKGPREFIX}-packaging>0:../../devel/py-packaging
#TEST_DEPENDS+=	${PYPKGPREFIX}-bokeh>=0:../../wip/py-bokeh

PYTHON_VERSIONS_INCOMPATIBLE=	310

# 12 failed, 8 passed
# due to missing test data

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
