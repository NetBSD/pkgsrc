# $NetBSD: Makefile,v 1.1 2025/07/28 13:51:07 dkazankov Exp $

DISTNAME=	types_gdb-15.0.0.20250516
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/types-gdb/}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/python/typeshed
COMMENT=	Typing stubs for gdb
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

.include "../../lang/python/wheel.mk"

.include "../../mk/bsd.pkg.mk"
