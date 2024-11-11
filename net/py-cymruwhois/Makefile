# $NetBSD: Makefile,v 1.10 2024/11/11 07:28:47 wiz Exp $

DISTNAME=	cymruwhois-1.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
PKGREVISION=	3
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cymruwhois/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/JustinAzoff/python-cymruwhois
COMMENT=	Client for the whois.cymru.com service
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} cymruwhois cymruwhois${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
