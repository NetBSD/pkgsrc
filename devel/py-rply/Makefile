# $NetBSD: Makefile,v 1.5 2017/08/03 13:54:38 adam Exp $

DISTNAME=	rply-0.7.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rply/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/alex/rply/
COMMENT=	Pure Python Lex/Yacc that works with RPython
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-appdirs-[0-9]*:../../devel/py-appdirs

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
