# $NetBSD: Makefile,v 1.10 2017/02/25 17:40:17 wiz Exp $

VERSION=	2.0.12
DISTNAME=	pyspf-${VERSION}t
PKGNAME=	${PYPKGPREFIX}-spf-${VERSION}
PKGREVISION=	1
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyspf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/pyspf
COMMENT=	Python implementation of the RFC 4408 SPF protocol
LICENSE=	python-software-foundation

EGG_NAME=	${DISTNAME:S/t$//}
WRKSRC=		${WRKDIR}/${DISTNAME:S/t$//}

.include "../../lang/python/pyversion.mk"

.if ${PYVERSSUFFIX} == "2.7"
DEPENDS+=	${PYPKGPREFIX}-pydns-[0-9]*:../../net/py-pydns
DEPENDS+=	${PYPKGPREFIX}-ipaddress-[0-9]*:../../net/py-ipaddress
.else
DEPENDS+=	${PYPKGPREFIX}-py3dns-[0-9]*:../../net/py-py3dns
.endif

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
