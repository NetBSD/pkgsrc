# $NetBSD: Makefile,v 1.4 2025/04/22 20:09:48 wiz Exp $

DISTNAME=	ply-3.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/ply/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dabeaz.com/ply/
COMMENT=	Lex an yacc parsing tools for Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
