# $NetBSD: Makefile,v 1.1 2017/10/16 17:03:06 adam Exp $

DISTNAME=	jedi-0.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	editors python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jedi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/davidhalter/jedi
COMMENT=	Autocompletion tool for Python that can be used for text editors
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-parso>=0.1.0:../../lang/py-parso
DEPENDS+=	${PYPKGPREFIX}-readline-[0-9]*:../../devel/py-readline

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
