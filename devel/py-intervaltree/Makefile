# $NetBSD: Makefile,v 1.2 2019/01/04 22:56:59 adam Exp $

DISTNAME=	intervaltree-3.0.2
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
