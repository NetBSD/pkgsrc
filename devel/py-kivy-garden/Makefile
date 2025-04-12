# $NetBSD: Makefile,v 1.7 2025/04/12 11:33:33 adam Exp $

DISTNAME=	Kivy%20Garden-0.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl:S/%20/-/}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=K/Kivy-garden/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kivy-garden/garden
COMMENT=	Garden tool for kivy flowers
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

WRKSRC=		${WRKDIR}/${DISTNAME:S/%20/\ /}

WHEEL_NAME=	kivy_garden-${PKGVERSION_NOREV}

post-install:
.for bin in garden garden.bat
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
