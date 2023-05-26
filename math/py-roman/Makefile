# $NetBSD: Makefile,v 1.16 2023/05/26 19:44:49 adam Exp $

DISTNAME=	roman-4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/roman/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/roman
COMMENT=	Integer to Roman numerals converter for Python
LICENSE=	zpl-2.1

CONFLICTS+=	${PYPKGPREFIX}-docutils<=0.7

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} roman roman-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
