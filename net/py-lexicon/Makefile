# $NetBSD: Makefile,v 1.1 2016/11/21 11:56:28 fhajny Exp $

DISTNAME=	lexicon-1.1.18
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=AnalogJ/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AnalogJ/lexicon/
COMMENT=	Manipulate DNS records on various DNS providers
LICENSE=	mit

GITHUB_PROJECT=	lexicon
GITHUB_TAG=	v${PKGVERSION_NOREV}

DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-tldextract-[0-9]*:../../net/py-tldextract

# Python 3 not currently supported
PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
