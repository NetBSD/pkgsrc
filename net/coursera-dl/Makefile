# $NetBSD: Makefile,v 1.5 2022/01/04 20:54:24 wiz Exp $

DISTNAME=	coursera-dl-0.8.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=coursera-dl/}
GITHUB_TAG=	0.8.0
PKGREVISION=	3
CATEGORIES=	net python

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://github.com/coursera-dl/coursera-dl
COMMENT=	Download course ressources for Coursera classes
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.1.3:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-requests>=2.10.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=1.5.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.10:../../www/py-urllib3
DEPENDS+=	${PYPKGPREFIX}-asn1>=0.1.7:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-keyring>=4.0:../../security/py-keyring

PYTHON_SELF_CONFLICT=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-keyring

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
