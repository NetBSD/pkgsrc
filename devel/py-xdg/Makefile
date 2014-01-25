# $NetBSD: Makefile,v 1.4 2014/01/25 10:30:05 wiz Exp $

DISTNAME=	pyxdg-0.19
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	http://www.freedesktop.org/~lanius/

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://freedesktop.org/wiki/Software/pyxdg
COMMENT=	Python library for XDG
LICENSE=	gnu-lgpl-v2

PYTHON_VERSIONS_INCOMPATIBLE=	33

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
