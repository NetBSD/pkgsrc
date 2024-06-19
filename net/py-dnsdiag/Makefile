# $NetBSD: Makefile,v 1.10 2024/06/19 05:08:23 adam Exp $

DISTNAME=	dnsdiag-2.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dnsdiag/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dnsdiag.org/
COMMENT=	DNS Diagnostics and Performance Measurement Tools
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-cryptography>=42.0.7:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-cymruwhois>=1.6:../../net/py-cymruwhois
DEPENDS+=	${PYPKGPREFIX}-dns>=2.6.1:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-h2>=4.1.0:../../www/py-h2
DEPENDS+=	${PYPKGPREFIX}-httpx>=0.27.0:../../www/py-httpx

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
.for bin in dnseval dnsping dnstraceroute
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin}.py ${bin}-${PYVERSSUFFIX} && ${RM} -f ${bin} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
