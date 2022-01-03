# $NetBSD: Makefile,v 1.1 2022/01/03 10:46:49 wiz Exp $

DISTNAME=	kivy-garden-0.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/kivy-garden/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kivy-garden/garden
COMMENT=	Garden tool for kivy flowers
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

USE_LANGUAGES=	c

PYTHON_VERSIONS_INCOMPATIBLE=	27

WRKSRC=		${WRKDIR}/${DISTNAME:S/kivy-//}
EGG_NAME=	Kivy_Garden-${PKGVERSION_NOREV}

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/garden  ${DESTDIR}${PREFIX}/bin/garden-${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/garden.bat  ${DESTDIR}${PREFIX}/bin/garden.bat-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
