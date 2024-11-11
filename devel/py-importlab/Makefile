# $NetBSD: Makefile,v 1.4 2024/11/11 07:28:11 wiz Exp $

DISTNAME=	importlab-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/importlab/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/importlab
COMMENT=	Library to calculate python dependency graphs
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-networkx>=2:../../math/py-networkx

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} importlab importlab-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
