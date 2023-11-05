# $NetBSD: Makefile,v 1.8 2023/11/05 23:44:05 wiz Exp $

DISTNAME=	confusable_homoglyphs-3.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/confusable_homoglyphs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/vhf/confusable_homoglyphs
COMMENT=	Detect confusable usage of unicode homoglyphs
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin \
		&& ${MV} confusable_homoglyphs confusable_homoglyphs-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
