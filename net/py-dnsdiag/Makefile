# $NetBSD: Makefile,v 1.5 2020/08/03 14:11:32 adam Exp $

DISTNAME=	dnsdiag-1.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dnsdiag/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dnsdiag.org/
COMMENT=	DNS Diagnostics and Performance Measurement Tools
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-cymruwhois>=1.6:../../net/py-cymruwhois
DEPENDS+=	${PYPKGPREFIX}-dns>=1.15.0:../../net/py-dns

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
.for bin in dnseval dnsping dnstraceroute
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin}.py ${bin}-${PYVERSSUFFIX} && ${RM} -f ${bin} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
