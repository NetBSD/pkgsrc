# $NetBSD: Makefile,v 1.45 2024/11/11 07:28:30 wiz Exp $

DISTNAME=	xdis-6.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xdis/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rocky/python-xdis
COMMENT=	Python cross-version byte-code disassembler and marshal routines
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.2:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pydisasm pydisasm-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
