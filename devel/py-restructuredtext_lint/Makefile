# $NetBSD: Makefile,v 1.6 2022/01/05 15:41:07 wiz Exp $

DISTNAME=	restructuredtext_lint-1.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/restructuredtext_lint/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/twolfson/restructuredtext-lint
COMMENT=	reStructuredText linter
LICENSE=	unlicense

DEPENDS+=	${PYPKGPREFIX}-docutils>=0.11:../../textproc/py-docutils

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

post-install:
.for bin in restructuredtext-lint rst-lint
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
