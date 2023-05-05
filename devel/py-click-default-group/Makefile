# $NetBSD: Makefile,v 1.1 2023/05/05 10:40:43 wiz Exp $

DISTNAME=	click-default-group-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/click-default-group/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sublee/click-default-group/
COMMENT=	Extends click.Group to invoke a command without explicit subcommand name
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-click>=0:../../devel/py-click
# no tests included in pypi distfile
#TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
