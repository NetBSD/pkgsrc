# $NetBSD: Makefile,v 1.102 2026/05/10 08:35:59 adam Exp $

DISTNAME=	dns_lexicon-3.25.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/dns_//}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dns-lexicon/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dns-lexicon/dns-lexicon
COMMENT=	Manipulate DNS records on various DNS providers
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-dns>=2:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-otp>=2:../../security/py-otp
DEPENDS+=	${PYPKGPREFIX}-requests>=2:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-unixsocket>=0.4:../../devel/py-requests-unixsocket
DEPENDS+=	${PYPKGPREFIX}-tldextract>=2:../../net/py-tldextract
DEPENDS+=	${PYPKGPREFIX}-yaml>=3:../../textproc/py-yaml

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	lexicon

PYTHON_VERSIONS_INCOMPATIBLE=	310

PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
