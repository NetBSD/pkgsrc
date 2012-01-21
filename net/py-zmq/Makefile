# $NetBSD: Makefile,v 1.1 2012/01/21 20:17:27 apb Exp $
#

DISTNAME=	pyzmq-2.1.10
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	net
MASTER_SITES=	https://github.com/zeromq/pyzmq/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zeromq/pyzmq/downloads/
COMMENT=	Python bindings for zeromq
LICENSE=	gnu-lgpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/python/distutils.mk"
.include "../../net/zeromq/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
