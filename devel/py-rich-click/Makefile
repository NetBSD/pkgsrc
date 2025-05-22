# $NetBSD: Makefile,v 1.7 2025/05/22 06:01:08 adam Exp $

DISTNAME=	rich_click-1.8.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rich-click/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/ewels/rich-click
COMMENT=	Format click help output nicely with rich
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-click>=7:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-rich>=10.7:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} rich-click rich-click-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
