# $NetBSD: Makefile,v 1.2 2018/07/24 10:00:08 adam Exp $

DISTNAME=	archinfo-7.8.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/archinfo/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/angr/archinfo
COMMENT=	Classes with architecture-specific information
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
