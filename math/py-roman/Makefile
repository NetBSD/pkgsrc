# $NetBSD: Makefile,v 1.15 2023/05/02 16:37:49 wiz Exp $

DISTNAME=	roman-4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/roman/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/roman
COMMENT=	Integer to Roman numerals converter for Python
LICENSE=	python-software-foundation

CONFLICTS+=	${PYPKGPREFIX}-docutils<=0.7

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} roman roman-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
