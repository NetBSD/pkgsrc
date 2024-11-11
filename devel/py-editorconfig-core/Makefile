# $NetBSD: Makefile,v 1.8 2024/11/11 07:28:07 wiz Exp $

DISTNAME=	EditorConfig-0.12.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/EditorConfig/editorconfig-core/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=E/EditorConfig/}

MAINTAINER=	nros@users.sourceforge.net
HOMEPAGE=	https://editorconfig.org/
COMMENT=	Editorconfig python library
LICENSE=	python-software-foundation AND modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=42.2:../../devel/py-setuptools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} editorconfig editorconfig-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
