# $NetBSD: Makefile,v 1.1 2016/06/30 17:48:21 wiz Exp $

DISTNAME=	dnsdiag-1.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dnsdiag/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dnsdiag.org/
COMMENT=	DNS Diagnostics and Performance Measurement Tools
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-cymruwhois-[0-9]*:../../net/py-cymruwhois

USE_LANGUAGES=	# none

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
FILES_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	for i in dnseval dnsping dnstraceroute; do \
		mv $$i $$i-${PYVERSSUFFIX}; \
	done

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
