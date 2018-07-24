# $NetBSD: Makefile,v 1.1 2018/07/24 15:08:19 adam Exp $

DISTNAME=	PyHamcrest-1.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^PyH/h/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyHamcrest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hamcrest/PyHamcrest
COMMENT=	Framework for writing matcher objects
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six>=1.4:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
