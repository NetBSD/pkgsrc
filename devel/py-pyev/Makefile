# $NetBSD: Makefile,v 1.6 2016/06/08 17:43:26 wiz Exp $
#

VERS=		0.8.1-4.04
PKGNAME=	${PYPKGPREFIX}-pyev-${VERS}
DISTNAME=	pyev-${VERS}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyev/}
USE_LANGUAGES+=	c

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_PYPI:=p/pyev/}
COMMENT=	Python interface to libev
LICENSE=	modified-bsd
PYDISTUTILSPKG=	yes

.include "../../devel/libev/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
