# $NetBSD: Makefile,v 1.18 2018/01/24 10:17:03 adam Exp $

DISTNAME=	ZConfig-3.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=Z/ZConfig/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/ZConfig
COMMENT=	Configuration library
LICENSE=	zpl-2.1

# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
#BUILD_DEPENDS+=	${PYPKGPREFIX}-manuel-[0-9]*:../../?/py-manuel
#BUILD_DEPENDS+=	${PYPKGPREFIX}-zope-testrunner-[0-9]*:../../?/py-zope-testrunner

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} zconfig zconfig${PYVERSSUFFIX} && \
	${MV} zconfig_schema2html zconfig_schema2html${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
