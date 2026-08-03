# $NetBSD: Makefile,v 1.2 2026/08/03 10:15:13 adam Exp $

DISTNAME=	rfc6555-0.1.0
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rfc6555/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.github.com/sethmlarson/rfc6555
COMMENT=	Implementation of the Happy Eyeballs Algorithm described in RFC 6555
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
