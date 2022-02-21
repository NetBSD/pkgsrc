# $NetBSD: Makefile,v 1.6 2022/02/21 19:08:36 adam Exp $

DISTNAME=	stone-3.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/stone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dropbox/stone
COMMENT=	Interface description language (IDL) for APIs
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-ply>=3.4:../../devel/py-ply
DEPENDS+=	${PYPKGPREFIX}-six>=1.12.0:../../lang/py-six
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

# https://github.com/dropbox/stone/issues/266
post-extract:
	${ECHO} 'ply>= 3.4' > ${WRKSRC}/requirements.txt
	${ECHO} 'six>= 1.12.0' >> ${WRKSRC}/requirements.txt

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} stone stone-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
