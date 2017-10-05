# $NetBSD: Makefile,v 1.4 2017/10/05 09:16:10 adam Exp $

DISTNAME=	cymruwhois-1.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cymruwhois/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/JustinAzoff/python-cymruwhois
COMMENT=	Client for the whois.cymru.com service
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} cymruwhois cymruwhois${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
