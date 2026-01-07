# $NetBSD: Makefile,v 1.33 2026/01/07 08:48:26 wiz Exp $

DISTNAME=	pysmbc-1.0.25.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	3
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pysmbc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hamano/pysmbc
COMMENT=	Python bindings for libsmbclient
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
#TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_TOOLS+=	pkg-config

.include "../../net/samba4/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
