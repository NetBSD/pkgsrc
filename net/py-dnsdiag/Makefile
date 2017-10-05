# $NetBSD: Makefile,v 1.3 2017/10/05 09:53:12 adam Exp $

DISTNAME=	dnsdiag-1.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dnsdiag/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dnsdiag.org/
COMMENT=	DNS Diagnostics and Performance Measurement Tools
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-dns>=1.15.0:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-cymruwhois>=1.6:../../net/py-cymruwhois

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} dnseval.py dnseval${PYVERSSUFFIX} && ${RM} dnseval && \
		${MV} dnsping.py dnsping${PYVERSSUFFIX} && ${RM} dnsping && \
		${MV} dnstraceroute.py dnstraceroute${PYVERSSUFFIX} && \
		${RM} dnstraceroute || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
