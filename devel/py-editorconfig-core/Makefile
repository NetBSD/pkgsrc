# $NetBSD: Makefile,v 1.12 2025/06/11 13:12:06 adam Exp $

DISTNAME=	editorconfig-0.17.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-/-core-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=E/EditorConfig/}

MAINTAINER=	nros@users.sourceforge.net
HOMEPAGE=	https://editorconfig.org/
COMMENT=	Editorconfig python library
LICENSE=	python-software-foundation AND modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=80.9.0:../../devel/py-setuptools

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} editorconfig editorconfig-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
