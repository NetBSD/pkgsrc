# $NetBSD: Makefile,v 1.12 2018/06/15 08:11:25 adam Exp $

DISTNAME=	orderedmultidict-1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/orderedmultidict/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gruns/orderedmultidict
COMMENT=	Ordered Multivalue Dictionary - omdict
LICENSE=	unlicense

DEPENDS+=	${PYPKGPREFIX}-six>=1.8.0:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
