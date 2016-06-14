# $NetBSD: Makefile,v 1.1 2016/06/14 07:58:40 kamil Exp $

DISTNAME=	pyaes-1.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_GITHUB:=ricmoo/}
GITHUB_PROJECT=	pyaes
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ricmoo/pyaes/
COMMENT=	Pure-Python implementation of AES block-cipher
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
