# $NetBSD: Makefile,v 1.6 2016/07/09 13:04:00 wiz Exp $

DISTNAME=	netifaces-0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://alastairs-place.net/projects/netifaces/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://alastairs-place.net/projects/netifaces/
COMMENT=	Portable access to network interfaces from Python
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # not yet ported as of 0.8

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
