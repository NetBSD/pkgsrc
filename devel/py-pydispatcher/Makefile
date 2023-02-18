# $NetBSD: Makefile,v 1.8 2023/02/18 20:22:02 adam Exp $

DISTNAME=	PyDispatcher-2.0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyDispatcher/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mcfletch/pydispatcher
COMMENT=	Multi-producer-multi-consumer signal dispatching mechanism
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
