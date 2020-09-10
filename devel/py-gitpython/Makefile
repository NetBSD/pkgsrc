# $NetBSD: Makefile,v 1.1 2020/09/10 15:05:55 taca Exp $

DISTNAME=	GitPython-3.1.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gitpython/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gitpython-developers/GitPython
COMMENT=	Python Git Library
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-gitdb>=4.0.1:../../devel/py-gitdb

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
