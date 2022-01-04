# $NetBSD: Makefile,v 1.3 2022/01/04 20:52:52 wiz Exp $

DISTNAME=	beniget-0.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
