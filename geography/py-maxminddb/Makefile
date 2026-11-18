# $NetBSD: Makefile,v 1.15 2026/11/18 08:44:28 adam Exp $

DISTNAME=	maxminddb-3.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	geography python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/maxminddb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/maxmind/MaxMind-DB-Reader-python
COMMENT=	Reader for the MaxMind DB format
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm

MAKE_ENV+=	MAXMINDDB_USE_SYSTEM_LIBMAXMINDDB=1

.include "../../geography/libmaxminddb/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
