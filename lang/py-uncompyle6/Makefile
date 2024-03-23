# $NetBSD: Makefile,v 1.34 2024/03/23 07:15:01 adam Exp $

DISTNAME=	uncompyle6-3.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uncompyle6/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rocky/python-uncompyle6
COMMENT=	Python cross-version byte-code decompiler
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-spark-parser>=1.8.9:../../lang/py-spark-parser
DEPENDS+=	${PYPKGPREFIX}-xdis>=6.0.8:../../devel/py-xdis

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# ModuleNotFoundError: No module named '__pkginfo__'
pre-configure:
	${RM} ${WRKSRC}/pyproject.toml

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pydisassemble pydisassemble-${PYVERSSUFFIX} && \
	${MV} uncompyle6 uncompyle6-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
