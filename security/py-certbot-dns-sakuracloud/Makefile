# $NetBSD: Makefile,v 1.1 2019/01/15 12:01:49 triaxx Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/certbot/certbot-dns-sakuracloud/}
CATEGORIES=	security

COMMENT=	Sakura Cloud DNS Authenticator plugin for Certbot
MAINTAINER=	triaxx@NetBSD.org
LICENSE=	apache-2.0

.include "../../security/py-certbot/Makefile.common"

DEPENDS+=	${PYPKGPREFIX}-acme>=0.21.1:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-certbot>=0.21.1:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-lexicon-[0-9]*:../../net/py-lexicon
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface

EGG_NAME=	${DISTNAME:S/certbot/certbot_dns_sakuracloud/}

PYSETUPSUBDIR=	certbot-dns-sakuracloud

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
