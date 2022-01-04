# $NetBSD: Makefile,v 1.3 2022/01/04 20:53:46 wiz Exp $

DISTNAME=	unittest-mixins-1.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
