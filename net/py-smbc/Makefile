# $NetBSD: Makefile,v 1.6 2019/11/23 08:45:45 mef Exp $

DISTNAME=	pysmbc-1.0.18
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pysmbc/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hamano/pysmbc
COMMENT=	Python bindings for libsmbclient
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config

.include "../../net/samba4/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
