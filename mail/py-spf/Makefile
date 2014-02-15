# $NetBSD: Makefile,v 1.1 2014/02/15 13:26:59 darcy Exp $
# FreeBSD Id: head/mail/py-spf/Makefile 344301 2014-02-14 19:41:11Z sunpoet

VERSION=	2.0.8
DISTNAME=	pyspf-${VERSION}
PKGNAME=	${PYTHON_PKGNAMEPREFIX}spf-${VERSION}
CATEGORIES=	mail python
MASTER_SITES=	https://pypi.python.org/packages/source/p/pyspf

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/pyspf
COMMENT=	Python implementation of the RFC 4408 SPF protocol

LICENSE=	python-software-foundation

DEPENDS+=	${PYPKGPREFIX}-dns>=0:../../net/py-dns
EGG_NAME=	pyspf-${VERSION}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
