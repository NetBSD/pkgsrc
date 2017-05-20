# $NetBSD: Makefile,v 1.2 2017/05/20 06:11:21 adam Exp $

DISTNAME=	Automat-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=A/Automat/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/glyph/Automat
COMMENT=	Self-service finite-state machines for the programmer on the go
LICENSE=	mit

USE_LANGUAGES=	# none

BUILD_DEPENDS+=	${PYPKGPREFIX}-m2r-[0-9]*:../../textproc/py-m2r
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-attrs-[0-9]*:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/automat-visualize \
		${DESTDIR}${PREFIX}/bin/automat-visualize${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
