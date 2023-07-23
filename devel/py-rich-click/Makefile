# $NetBSD: Makefile,v 1.3 2023/07/23 02:09:54 wiz Exp $

DISTNAME=	rich-click-1.6.1
PKGNAME=	${PYPKGPREFIX}-rich-click-1.6.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rich-click/}

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://pypi.python.org/project/rich-click/
COMMENT=	Format click help output nicely with rich
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-click>0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-rich>0:../../comms/py-rich

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
