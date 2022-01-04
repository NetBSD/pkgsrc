# $NetBSD: Makefile,v 1.6 2022/01/04 19:54:28 wiz Exp $

DISTNAME=	rpyc-4.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rpyc/}

MAINTAINER=	gde@llew.me
HOMEPAGE=	http://rpyc.readthedocs.org/
COMMENT=	Remote Python Call (RPyC), a transparent and symmetric RPC library
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-plumbum>=1.6.1:../../devel/py-plumbum

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
