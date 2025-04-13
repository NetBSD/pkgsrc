# $NetBSD: Makefile,v 1.11 2025/04/13 07:22:37 adam Exp $

DISTNAME=	confusable_homoglyphs-3.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/confusable_homoglyphs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/vhf/confusable_homoglyphs
COMMENT=	Detect confusable usage of unicode homoglyphs
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
# cli
DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} confusable_homoglyphs confusable_homoglyphs-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
