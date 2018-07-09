# $NetBSD: Makefile,v 1.7 2018/07/09 19:18:19 adam Exp $

DISTNAME=	rply-0.7.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rply/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alex/rply
COMMENT=	Pure Python Lex/Yacc that works with RPython
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-appdirs-[0-9]*:../../devel/py-appdirs

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
