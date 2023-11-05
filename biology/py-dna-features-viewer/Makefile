# $NetBSD: Makefile,v 1.2 2023/11/05 20:00:41 wiz Exp $

DISTNAME=	dna_features_viewer-3.1.3
PKGNAME=	${PYPKGPREFIX}-dna-features-viewer-3.1.3
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dna-features-viewer/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://pypi.python.org/project/dna-features-viewer/
COMMENT=	Python library to visualize DNA features, e.g. GenBank or Gff files
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-biopython>0:../../biology/py-biopython
DEPENDS+=	${PYPKGPREFIX}-bcbio-gff>0:../../biology/py-bcbio-gff
DEPENDS+=	${PYPKGPREFIX}-packaging>0:../../devel/py-packaging

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
