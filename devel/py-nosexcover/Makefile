# $NetBSD: Makefile,v 1.5 2022/08/24 09:25:56 wiz Exp $

DISTNAME=	nosexcover-1.0.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nosexcover/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cmheisel/nose-xcover/
COMMENT=	Extends nose.plugins.cover to add Cobertura-style XML reports
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

PYTHON_VERSIONED_DEPENDENCIES+=	coverage

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
