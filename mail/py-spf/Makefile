# $NetBSD: Makefile,v 1.8 2016/06/30 18:03:46 wiz Exp $

VERSION=	2.0.8
DISTNAME=	pyspf-${VERSION}
PKGNAME=	${PYPKGPREFIX}-spf-${VERSION}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyspf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/pyspf
COMMENT=	Python implementation of the RFC 4408 SPF protocol
LICENSE=	python-software-foundation

DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
