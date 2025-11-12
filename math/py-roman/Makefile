# $NetBSD: Makefile,v 1.25 2025/11/12 09:03:52 adam Exp $

DISTNAME=	roman-5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/roman/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/roman
COMMENT=	Integer to Roman numerals converter for Python
LICENSE=	zpl-2.1

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>78:../../devel/py-setuptools

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} roman roman-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
