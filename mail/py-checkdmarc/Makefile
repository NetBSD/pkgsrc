# $NetBSD: Makefile,v 1.4 2023/10/28 19:57:10 wiz Exp $

DISTNAME=	checkdmarc-4.4.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/checkdmarc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/domainaware/checkdmarc
COMMENT=	Python module and command line parser for SPF and DMARC records
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.8.1:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-dns>=2.0.0:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-expiringdict>=1.1.4:../../devel/py-expiringdict
DEPENDS+=	${PYPKGPREFIX}-pyleri>=1.3.2:../../devel/py-pyleri
DEPENDS+=	${PYPKGPREFIX}-publicsuffix2>=2.20191221:../../www/py-publicsuffix2
DEPENDS+=	${PYPKGPREFIX}-requests>=2.25.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-timeout-decorator>=0.4.1:../../devel/py-timeout-decorator

USE_LANGUAGES=	# none

REPLACE_PYTHON=	checkdmarc.py

PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-dns

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} checkdmarc checkdmarc-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
