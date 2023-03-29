# $NetBSD: Makefile,v 1.6 2023/03/29 09:34:04 wiz Exp $

DISTNAME=	arabic_reshaper-2.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/arabic-reshaper/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mpcabd/python-arabic-reshaper
COMMENT=	Reconstruct Arabic sentences
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} == 207
DEPENDS+=	${PYPKGPREFIX}-configparser-[0-9]*:../../devel/py-configparser
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
