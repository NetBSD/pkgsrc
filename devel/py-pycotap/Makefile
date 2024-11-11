# $NetBSD: Makefile,v 1.6 2024/11/11 07:28:20 wiz Exp $

DISTNAME=	pycotap-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycotap/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/remko/pycotap
COMMENT=	Tiny test runner that outputs TAP results to standard output
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	${RM} ${DESTDIR}${PREFIX}/COPYING

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
