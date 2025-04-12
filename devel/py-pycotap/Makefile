# $NetBSD: Makefile,v 1.7 2025/04/12 20:03:45 adam Exp $

DISTNAME=	pycotap-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycotap/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/remko/pycotap
COMMENT=	Tiny test runner that outputs TAP results to standard output
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

post-install:
	${RM} ${DESTDIR}${PREFIX}/COPYING

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
