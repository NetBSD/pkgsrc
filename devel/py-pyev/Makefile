# $NetBSD: Makefile,v 1.1 2012/09/01 22:11:38 mspo Exp $
#

VERS=		0.8.1-4.04
PKGNAME=	${PYPKGPREFIX}-pyev-${VERS}
DISTNAME=	pyev-${VERS}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyev/
USE_LANGUAGES+=	c

MAINTAINER=	pkgsrc-users@netbsd.org
HOMEPAGE=	http://pypi.python.org/packages/source/p/pyev/
COMMENT=	python interface to libev
LICENSE=	BSD
PYDISTUTILSPKG=	yes

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../devel/libev/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
