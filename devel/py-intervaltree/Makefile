# $NetBSD: Makefile,v 1.1 2017/03/20 21:59:04 minskim Exp $

DISTNAME=	intervaltree-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=i/intervaltree/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/chaimleib/intervaltree
COMMENT=	Editable interval tree data structure
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-sortedcontainers-[0-9]*:../../devel/py-sortedcontainers

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
