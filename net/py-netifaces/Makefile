#y$NetBSD: Makefile,v 1.3 2014/05/09 07:37:15 wiz Exp $

DISTNAME=	netifaces-0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://alastairs-place.net/projects/netifaces/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://alastairs-place.net/projects/netifaces/
COMMENT=	Portable access to network interfaces from Python
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.8

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
