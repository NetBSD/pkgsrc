# $NetBSD: Makefile,v 1.6 2024/11/11 07:28:04 wiz Exp $

DISTNAME=	contextlib2-21.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/contextlib2/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://contextlib2.readthedocs.org/
COMMENT=	Backports and enhancements for the contextlib module
LICENSE=	python-software-foundation AND apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
