# $NetBSD: Makefile,v 1.1 2018/02/15 16:44:30 minskim Exp $

DISTNAME=	restructuredtext-lint-1.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-/_/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=twolfson/}
GITHUB_PROJECT=	restructuredtext-lint

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/twolfson/restructuredtext-lint
COMMENT=	reStructuredText linter
LICENSE=	unlicense

DEPENDS+=	${PYPKGPREFIX}-docutils>=0.11:../../textproc/py-docutils

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"

post-install:
.for file in restructuredtext-lint rst-lint
	${MV} ${DESTDIR}${PREFIX}/bin/${file} \
		${DESTDIR}${PREFIX}/bin/${file}${PYVERSSUFFIX}
.endfor

.include "../../mk/bsd.pkg.mk"
