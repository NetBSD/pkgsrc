# $NetBSD: Makefile,v 1.7 2022/01/05 15:41:16 wiz Exp $

DISTNAME=	cymruwhois-1.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
PKGREVISION=	2
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cymruwhois/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/JustinAzoff/python-cymruwhois
COMMENT=	Client for the whois.cymru.com service
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} cymruwhois cymruwhois${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
