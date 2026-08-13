# $NetBSD: Makefile,v 1.16 2026/08/13 07:26:59 adam Exp $

DISTNAME=	dnsdiag-2.9.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dnsdiag/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dnsdiag.org/
COMMENT=	DNS Diagnostics and Performance Measurement Tools
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-aioquic>=1.2.0:../../www/py-aioquic
DEPENDS+=	${PYPKGPREFIX}-cryptography>=42.0.5:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-cymruwhois>=1.6:../../net/py-cymruwhois
DEPENDS+=	${PYPKGPREFIX}-dns>=2.8.0:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-h2>=4.1.0:../../www/py-h2
DEPENDS+=	${PYPKGPREFIX}-httpx>=0.27.0:../../www/py-httpx

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	dnseval dnsping dnstraceroute

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
