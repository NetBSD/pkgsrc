# $NetBSD: Makefile,v 1.33 2019/01/15 11:30:03 triaxx Exp $

DISTNAME=	lexicon-3.0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=AnalogJ/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AnalogJ/lexicon/
COMMENT=	Manipulate DNS records on various DNS providers
LICENSE=	mit

GITHUB_PROJECT=	lexicon
GITHUB_TAG=	v${PKGVERSION_NOREV}

EXTRACT_USING=	bsdtar
USE_TOOLS+=	bsdtar

DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-tldextract-[0-9]*:../../net/py-tldextract
DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

MESSAGE_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}

EGG_NAME=	${DISTNAME:S/lexicon/dns_lexicon/}

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/lexicon \
		${DESTDIR}${PREFIX}/bin/lexicon${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
