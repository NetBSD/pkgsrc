# $NetBSD: Makefile,v 1.2 2016/08/28 15:48:33 wiz Exp $

DISTNAME=	dnsdiag-1.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dnsdiag/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dnsdiag.org/
COMMENT=	DNS Diagnostics and Performance Measurement Tools
LICENSE=	2-clause-bsd

# cited as dependency, but dnsdiag installs conflicting files
#DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-cymruwhois-[0-9]*:../../net/py-cymruwhois

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	for i in dnseval dnsping dnstraceroute; do \
		mv $$i $$i-${PYVERSSUFFIX}; \
	done

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
