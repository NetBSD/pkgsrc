# $NetBSD: Makefile,v 1.9 2023/08/10 05:17:48 adam Exp $

DISTNAME=	dnsdiag-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dnsdiag/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dnsdiag.org/
COMMENT=	DNS Diagnostics and Performance Measurement Tools
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-cymruwhois>=1.6:../../net/py-cymruwhois
DEPENDS+=	${PYPKGPREFIX}-dns>=2.3.0:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-requests>=2.28.2:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-toolbelt>=0.9.1:../../devel/py-requests-toolbelt

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
.for bin in dnseval dnsping dnstraceroute
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin}.py ${bin}-${PYVERSSUFFIX} && ${RM} -f ${bin} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
