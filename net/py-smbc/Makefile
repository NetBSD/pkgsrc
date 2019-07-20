# $NetBSD: Makefile,v 1.4 2019/07/20 22:46:41 wiz Exp $

DISTNAME=	pysmbc-1.0.16
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
