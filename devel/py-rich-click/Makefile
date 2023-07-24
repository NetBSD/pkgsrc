# $NetBSD: Makefile,v 1.4 2023/07/24 04:45:33 adam Exp $

DISTNAME=	rich-click-1.6.1
PKGNAME=	${PYPKGPREFIX}-rich-click-1.6.1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rich-click/}

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/ewels/rich-click
COMMENT=	Format click help output nicely with rich
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-click>=7:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-rich>=10.7.0:../../comms/py-rich

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} rich-click rich-click-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
