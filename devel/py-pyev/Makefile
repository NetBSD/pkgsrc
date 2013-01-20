# $NetBSD: Makefile,v 1.5 2013/01/20 03:35:46 mspo Exp $
#

VERS=		0.8.1-4.04
PKGNAME=	${PYPKGPREFIX}-pyev-${VERS}
DISTNAME=	pyev-${VERS}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyev/
USE_LANGUAGES+=	c

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/packages/source/p/pyev/
COMMENT=	Python interface to libev
LICENSE=	modified-bsd
PYDISTUTILSPKG=	yes

.include "../../devel/libev/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
