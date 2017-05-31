# $NetBSD: Makefile,v 1.13 2017/05/31 10:35:24 fhajny Exp $

DISTNAME=	lexicon-2.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=AnalogJ/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AnalogJ/lexicon/
COMMENT=	Manipulate DNS records on various DNS providers
LICENSE=	mit

GITHUB_PROJECT=	lexicon
GITHUB_TAG=	v${PKGVERSION_NOREV}

DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-tldextract-[0-9]*:../../net/py-tldextract

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
