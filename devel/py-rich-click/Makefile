# $NetBSD: Makefile,v 1.1 2023/07/20 14:23:56 bacon Exp $

DISTNAME=	rich-click-1.6.1
PKGNAME=	${PYPKGPREFIX}-rich-click-1.6.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rich-click/}

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://pypi.python.org/project/rich-click/
COMMENT=	Format click help output nicely with rich
LICENSE=	mit

DEPENDS=	${PYPKGPREFIX}-click>0:../../devel/py-click \
		${PYPKGPREFIX}-rich>0:../../comms/py-rich

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
