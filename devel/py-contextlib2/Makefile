# $NetBSD: Makefile,v 1.7 2025/04/12 09:54:04 adam Exp $

DISTNAME=	contextlib2-21.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/contextlib2/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://contextlib2.readthedocs.org/
COMMENT=	Backports and enhancements for the contextlib module
LICENSE=	python-software-foundation AND apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
