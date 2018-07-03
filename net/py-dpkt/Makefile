# $NetBSD: Makefile,v 1.10 2018/07/03 05:03:28 adam Exp $

DISTNAME=	dpkt-1.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	http://dpkt.googlecode.com/files/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://github.com/kbandla/dpkt
COMMENT=	Python packet creation / parsing library
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 1.8

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
