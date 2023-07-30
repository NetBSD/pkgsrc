# $NetBSD: Makefile,v 1.12 2023/07/30 15:32:49 adam Exp $

DISTNAME=	aiosmtpd-1.4.4.post2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiosmtpd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/aiosmtpd
COMMENT=	Asyncio based SMTP server
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-atpublic-[0-9]*:../../devel/py-atpublic
DEPENDS+=	${PYPKGPREFIX}-attrs-[0-9]*:../../devel/py-attrs

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

pre-configure:
	${CHMOD} -R go-w ${WRKSRC}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} aiosmtpd aiosmtpd-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
