# $NetBSD: Makefile,v 1.9 2025/02/06 17:09:15 adam Exp $

DISTNAME=	editorconfig-0.17.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-/-core-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=E/EditorConfig/}

MAINTAINER=	nros@users.sourceforge.net
HOMEPAGE=	https://editorconfig.org/
COMMENT=	Editorconfig python library
LICENSE=	python-software-foundation AND modified-bsd

WHEEL_NAME=	${DISTNAME:S/editorc/EditorC/}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.2:../../devel/py-setuptools

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} editorconfig editorconfig-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
