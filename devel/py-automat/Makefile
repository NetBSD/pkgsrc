# $NetBSD: Makefile,v 1.5 2022/01/04 20:52:51 wiz Exp $

DISTNAME=	Automat-0.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
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
