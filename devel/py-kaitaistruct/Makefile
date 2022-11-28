# $NetBSD: Makefile,v 1.6 2022/11/28 18:42:09 adam Exp $

DISTNAME=	kaitaistruct-0.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/kaitaistruct/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kaitai.io/
COMMENT=	Kaitai Struct declarative parser generator for binary data
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-enum34-[0-9]*:../../devel/py-enum34
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
