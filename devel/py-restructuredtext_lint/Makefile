# $NetBSD: Makefile,v 1.9 2025/12/26 09:02:54 adam Exp $

DISTNAME=	restructuredtext_lint-2.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/restructuredtext_lint/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/twolfson/restructuredtext-lint
COMMENT=	reStructuredText linter
LICENSE=	unlicense

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.11:../../textproc/py-docutils

USE_LANGUAGES=	# none

post-install:
.for bin in restructuredtext-lint rst-lint
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
