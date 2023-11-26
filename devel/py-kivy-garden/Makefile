# $NetBSD: Makefile,v 1.3 2023/11/26 14:34:00 adam Exp $

DISTNAME=	Kivy%20Garden-0.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl:S/%20/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/kivy-garden/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kivy-garden/garden
COMMENT=	Garden tool for kivy flowers
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

PYTHON_VERSIONS_INCOMPATIBLE=	27

WRKSRC=		${WRKDIR}/${DISTNAME:S/%20/\ /}
WHEEL_NAME=	Kivy_Garden-${PKGVERSION_NOREV}

post-install:
.for bin in garden garden.bat
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
