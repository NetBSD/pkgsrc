# $NetBSD: Makefile,v 1.2 2018/08/23 07:51:00 adam Exp $

DISTNAME=	unittest-mixins-1.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/unittest-mixins/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nedbat/unittest-mixins
COMMENT=	Helpful mixins for unittest classes
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-six>=1.4.0:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
