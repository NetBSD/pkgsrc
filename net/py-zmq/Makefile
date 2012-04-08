# $NetBSD: Makefile,v 1.4 2012/04/08 19:09:10 wiz Exp $
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

.include "../../lang/python/distutils.mk"
.include "../../net/zeromq/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
