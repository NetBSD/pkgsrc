# $NetBSD: Makefile,v 1.7 2013/01/24 11:18:14 obache Exp $
#

DISTNAME=	pyzmq-2.1.11
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	net
MASTER_SITES=	http://cloud.github.com/downloads/zeromq/pyzmq/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zeromq/pyzmq/
COMMENT=	Python bindings for zeromq
LICENSE=	gnu-lgpl-v3

.include "../../lang/python/distutils.mk"
.include "../../net/zeromq/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
