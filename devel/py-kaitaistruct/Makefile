# $NetBSD: Makefile,v 1.7 2022/11/29 08:42:10 wiz Exp $

DISTNAME=	kaitaistruct-0.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/kaitaistruct/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kaitai.io/
COMMENT=	Kaitai Struct declarative parser generator for binary data
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-enum34-[0-9]*:../../devel/py-enum34
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
