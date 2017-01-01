# $NetBSD: Makefile,v 1.7 2017/01/01 14:43:51 wiz Exp $

DISTNAME=	netifaces-0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://alastairs-place.net/projects/netifaces/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://alastairs-place.net/projects/netifaces/
COMMENT=	Portable access to network interfaces from Python
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 0.8

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
