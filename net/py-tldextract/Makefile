# $NetBSD: Makefile,v 1.2 2017/06/22 09:34:47 adam Exp $

DISTNAME=	tldextract-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tldextract/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/john-kurkowski/tldextract/
COMMENT=	Accurately separate the TLD from the registered domain and subdomains
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-idna-[0-9]*:../../www/py-idna
DEPENDS+=	${PYPKGPREFIX}-requests-file>=1.4:../../devel/py-requests-file
DEPENDS+=	${PYPKGPREFIX}-requests>=2.1.0:../../devel/py-requests

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/tldextract \
		${DESTDIR}${PREFIX}/bin/tldextract${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
