# $NetBSD: Makefile,v 1.1 2021/12/07 18:03:07 wiz Exp $

DISTNAME=	requirements-parser-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requirements-parser/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/davidfischer/requirements-parser
COMMENT=	Parses Pip requirement files
LICENSE=	2-clause-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
