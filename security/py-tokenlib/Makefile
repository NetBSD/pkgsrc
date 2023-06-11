# $NetBSD: Makefile,v 1.1 2023/06/11 07:34:09 wiz Exp $

DISTNAME=	tokenlib-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tokenlib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mozilla-services/tokenlib
COMMENT=	Generic library for managing signed authentication tokens
LICENSE=	mpl-2.0

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
