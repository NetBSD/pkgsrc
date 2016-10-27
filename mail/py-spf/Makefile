# $NetBSD: Makefile,v 1.9 2016/10/27 12:25:05 jperkin Exp $

VERSION=	2.0.12
DISTNAME=	pyspf-${VERSION}t
PKGNAME=	${PYPKGPREFIX}-spf-${VERSION}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyspf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/pyspf
COMMENT=	Python implementation of the RFC 4408 SPF protocol
LICENSE=	python-software-foundation

EGG_NAME=	${DISTNAME:S/t$//}
WRKSRC=		${WRKDIR}/${DISTNAME:S/t$//}

DEPENDS+=	${PYPKGPREFIX}-pydns-[0-9]*:../../net/py-pydns

PYTHON_VERSIONS_ACCEPTED=      27 # py-pydns

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
