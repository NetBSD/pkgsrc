# $NetBSD: Makefile,v 1.1.1.1 2009/03/10 00:34:46 snj Exp $

DISTNAME=	pyxdg-0.17
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	http://www.freedesktop.org/~lanius/

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://freedesktop.org/wiki/Software/pyxdg
COMMENT=	Python library for XDG

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
