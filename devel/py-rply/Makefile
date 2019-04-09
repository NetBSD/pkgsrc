# $NetBSD: Makefile,v 1.8 2019/04/09 10:52:33 adam Exp $

DISTNAME=	rply-0.7.7
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
