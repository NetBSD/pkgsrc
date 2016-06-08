# $NetBSD: Makefile,v 1.7 2016/06/08 22:34:29 wiz Exp $

VERS=		0.9.0
PKGNAME=	${PYPKGPREFIX}-pyev-${VERS}
DISTNAME=	pyev-${VERS}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyev/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/pyev
COMMENT=	Python interface to libev
LICENSE=	modified-bsd

USE_LANGUAGES+=	c

BUILDLINK_API_DEPENDS.libev+=	libev>=4.15
.include "../../devel/libev/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
