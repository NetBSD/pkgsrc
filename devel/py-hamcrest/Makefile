# $NetBSD: Makefile,v 1.2 2022/01/04 20:53:09 wiz Exp $

DISTNAME=	PyHamcrest-1.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^PyH/h/}
PKGREVISION=	1
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
