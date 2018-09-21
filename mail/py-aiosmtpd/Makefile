# $NetBSD: Makefile,v 1.4 2018/09/21 10:43:45 adam Exp $

DISTNAME=	aiosmtpd-1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiosmtpd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/aiosmtpd
COMMENT=	Asyncio based SMTP server
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-atpublic-[0-9]*:../../devel/py-atpublic

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} aiosmtpd aiosmtpd-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
