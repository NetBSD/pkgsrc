# $NetBSD: Makefile,v 1.2 2020/06/02 19:58:00 adam Exp $

DISTNAME=	doc8-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/doc8/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/pycqa/doc8
COMMENT=	Opinionated style checker for rst styles of documentation
LICENSE=	apache-2.0

BUILD_DEPENDS+=	${PYPKGPREFIX}-pbr-[0-9]*:../../devel/py-pbr
DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-restructuredtext_lint>=0.7:../../devel/py-restructuredtext_lint
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-stevedore-[0-9]*:../../devel/py-stevedore

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} doc8 doc8-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
