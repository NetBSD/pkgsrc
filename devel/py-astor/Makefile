# $NetBSD: Makefile,v 1.16 2024/11/11 07:28:00 wiz Exp $

DISTNAME=	astor-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/astor/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/berkerpeksag/astor
COMMENT=	Read/rewrite/write Python ASTs
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

# as of 0.8.1
# 2 failed, 51 passed, 2 skipped, 732 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
