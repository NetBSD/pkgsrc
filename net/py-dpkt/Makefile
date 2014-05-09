# $NetBSD: Makefile,v 1.5 2014/05/09 07:37:15 wiz Exp $

DISTNAME=	dpkt-1.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	http://dpkt.googlecode.com/files/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://code.google.com/p/dpkt/
COMMENT=	Python packet creation / parsing library
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 1.8

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
