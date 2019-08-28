# $NetBSD: Makefile,v 1.3 2019/08/28 08:20:37 adam Exp $

DISTNAME=	prefixspan-0.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/prefixspan/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/chuanconggao/PrefixSpan-py
COMMENT=	PrefixSpan in Python 3
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-docopt>=0.6.2:../../devel/py-docopt
DEPENDS+=	${PYPKGPREFIX}-extratools>=0.8.1:../../devel/py-extratools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} prefixspan-cli prefixspan-cli-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
