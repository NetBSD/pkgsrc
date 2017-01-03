# $NetBSD: Makefile,v 1.3 2017/01/03 13:23:03 jperkin Exp $

DISTNAME=	python-cymruwhois-1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	nih
MASTER_SITES=	${MASTER_SITE_GITHUB:=JustinAzoff/}
GITHUB_PROJECT=	python-cymruwhois

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/cymruwhois
COMMENT=	Client for the whois.cymru.com service
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	# none

EGG_NAME=	${DISTNAME:S/python-//}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} cymruwhois cymruwhois-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
