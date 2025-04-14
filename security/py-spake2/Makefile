# $NetBSD: Makefile,v 1.8 2025/04/14 05:17:12 adam Exp $

DISTNAME=	spake2-0.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/spake2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/warner/python-spake2
COMMENT=	Pure-Python SPAKE2
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
