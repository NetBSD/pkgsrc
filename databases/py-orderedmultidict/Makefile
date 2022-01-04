# $NetBSD: Makefile,v 1.14 2022/01/04 20:52:43 wiz Exp $

DISTNAME=	orderedmultidict-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
