# $NetBSD: Makefile,v 1.6 2022/05/10 05:40:43 adam Exp $

DISTNAME=	aenum-3.1.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aenum/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ethanfurman/aenum
COMMENT=	Advanced Enumerations, NamedTuples, and NamedConstants
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
