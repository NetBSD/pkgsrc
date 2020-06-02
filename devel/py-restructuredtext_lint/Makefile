# $NetBSD: Makefile,v 1.2 2020/06/02 19:52:43 adam Exp $

DISTNAME=	restructuredtext_lint-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/restructuredtext_lint/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/twolfson/restructuredtext-lint
COMMENT=	reStructuredText linter
LICENSE=	unlicense

DEPENDS+=	${PYPKGPREFIX}-docutils>=0.11:../../textproc/py-docutils

USE_LANGUAGES=	# none

pre-configure:
	${FIND} ${WRKSRC} -type f -name '*.pyc' -exec ${RM} {} +

post-install:
.for bin in restructuredtext-lint rst-lint
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
