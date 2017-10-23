# $NetBSD: Makefile,v 1.1 2017/10/23 15:20:45 adam Exp $

DISTNAME=	visitor-0.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/visitor/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mbr/visitor
COMMENT=	Tiny pythonic visitor implementation
LICENSE=	mit

#DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
#BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
