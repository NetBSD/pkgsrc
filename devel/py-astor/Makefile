# $NetBSD: Makefile,v 1.11 2019/12/16 10:18:54 adam Exp $

DISTNAME=	astor-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/astor/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/berkerpeksag/astor
COMMENT=	Read/rewrite/write Python ASTs
LICENSE=	2-clause-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
