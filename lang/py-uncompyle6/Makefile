# $NetBSD: Makefile,v 1.36 2024/11/11 07:28:38 wiz Exp $

DISTNAME=	uncompyle6-3.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uncompyle6/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rocky/python-uncompyle6
COMMENT=	Python cross-version byte-code decompiler
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=71.0.3:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-spark-parser>=1.8.9:../../lang/py-spark-parser
DEPENDS+=	${PYPKGPREFIX}-xdis>=6.1.0:../../devel/py-xdis

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	uncompyle6/bin/pydisassemble.py
REPLACE_PYTHON+=	uncompyle6/bin/uncompile.py

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
.for bin in uncompyle6 uncompyle6-tokenize
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
