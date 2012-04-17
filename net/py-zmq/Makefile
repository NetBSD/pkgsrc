# $NetBSD: Makefile,v 1.5 2012/04/17 17:33:09 drochner Exp $
#

DISTNAME=	pyzmq-2.1.11
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	net
MASTER_SITES=	https://github.com/zeromq/pyzmq/downloads/
FETCH_USING=	curl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zeromq/pyzmq/
COMMENT=	Python bindings for zeromq
LICENSE=	gnu-lgpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/python/distutils.mk"
.include "../../net/zeromq/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
