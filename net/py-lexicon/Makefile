# $NetBSD: Makefile,v 1.31 2018/09/17 11:14:52 fhajny Exp $

DISTNAME=	lexicon-2.7.3
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
DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography

MESSAGE_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
