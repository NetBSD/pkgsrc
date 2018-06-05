# $NetBSD: Makefile,v 1.1 2018/06/05 19:34:21 minskim Exp $

DISTNAME=	doc8-0.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/doc8/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://launchpad.net/doc8
COMMENT=	Opinionated style checker for rst styles of documentation
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-restructuredtext_lint>=0.7:../../devel/py-restructuredtext_lint
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-stevedore-[0-9]*:../../devel/py-stevedore

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/doc8 \
	      ${DESTDIR}${PREFIX}/bin/doc8-${PYVERSSUFFIX}

.include "../../mk/bsd.pkg.mk"
