# $NetBSD: Makefile,v 1.3 2012/03/05 08:12:38 dholland Exp $
#

DISTNAME=	pyzmq-2.1.10
PKGREVISION=	1
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	net
MASTER_SITES=	https://github.com/zeromq/pyzmq/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zeromq/pyzmq/downloads/
COMMENT=	Python bindings for zeromq
LICENSE=	gnu-lgpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_INCOMPATIBLE=	24

.include "../../lang/python/distutils.mk"
.include "../../net/zeromq/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
