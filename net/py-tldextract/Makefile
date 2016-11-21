# $NetBSD: Makefile,v 1.1 2016/11/21 11:49:55 fhajny Exp $

DISTNAME=	tldextract-2.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=john-kurkowski/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/john-kurkowski/tldextract/
COMMENT=	Accurately separate the TLD from the registered domain and subdomains
LICENSE=	modified-bsd

GITHUB_PROJECT=	tldextract
GITHUB_TAG=	${PKGVERSION}

DEPENDS+=	${PYPKGPREFIX}-idna-[0-9]*:../../www/py-idna
DEPENDS+=	${PYPKGPREFIX}-requests-file>=1.4:../../devel/py-requests-file
DEPENDS+=	${PYPKGPREFIX}-requests>=2.1.0:../../devel/py-requests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
