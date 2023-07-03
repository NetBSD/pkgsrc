# $NetBSD: Makefile,v 1.2 2023/07/03 12:37:55 wiz Exp $

DISTNAME=	click-default-group-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/click-default-group/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sublee/click-default-group/
COMMENT=	Extends click.Group to invoke a command without explicit subcommand name
LICENSE=	modified-bsd

# no tests included in pypi distfile
#TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES=	click

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
