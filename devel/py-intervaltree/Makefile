# $NetBSD: Makefile,v 1.3 2020/12/14 14:23:46 adam Exp $

DISTNAME=	intervaltree-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/intervaltree/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/chaimleib/intervaltree
COMMENT=	Editable interval tree data structure
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=2.0:../../devel/py-sortedcontainers

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
