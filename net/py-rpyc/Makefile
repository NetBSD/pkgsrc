# $NetBSD: Makefile,v 1.3 2020/09/29 22:58:36 khorben Exp $

DISTNAME=	rpyc-3.4.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rpyc/}

MAINTAINER=	gde@llew.me
HOMEPAGE=	http://rpyc.readthedocs.org/
COMMENT=	Remote Python Call (RPyC), a transparent and symmetric RPC library
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-plumbum>=1.6.1:../../devel/py-plumbum

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
