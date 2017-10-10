# $NetBSD: Makefile,v 1.1 2017/10/10 07:27:10 adam Exp $

DISTNAME=	ordered-set-2.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/ordered-set/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/LuminosoInsight/ordered-set
COMMENT=	MutableSet that remembers its order
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
