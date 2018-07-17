# $NetBSD: Makefile,v 1.3 2018/07/17 06:21:58 adam Exp $

DISTNAME=	Automat-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=A/Automat/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/glyph/Automat
COMMENT=	Self-service finite-state machines for the programmer on the go
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-m2r-[0-9]*:../../textproc/py-m2r
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-attrs>=16.1.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} automat-visualize automat-visualize${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
