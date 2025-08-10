# $NetBSD: Makefile,v 1.11 2025/08/10 09:10:30 adam Exp $

DISTNAME=	maxminddb-2.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	geography python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/maxminddb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/maxmind/MaxMind-DB-Reader-python
COMMENT=	Reader for the MaxMind DB format
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm

.include "../../geography/libmaxminddb/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
