# $NetBSD: Makefile,v 1.12 2019/04/26 14:12:43 maya Exp $

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

PYTHON_VERSIONS_INCOMPATIBLE=	36 37 # not yet ported as of 1.8

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
