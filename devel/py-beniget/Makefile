# $NetBSD: Makefile,v 1.2 2021/11/18 17:51:00 adam Exp $

DISTNAME=	beniget-0.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/beniget/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/serge-sans-paille/beniget
COMMENT=	Extract semantic information about static Python code
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-gast>=0.5.0:../../devel/py-gast

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
