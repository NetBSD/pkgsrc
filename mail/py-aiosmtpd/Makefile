# $NetBSD: Makefile,v 1.3 2017/09/29 12:40:55 adam Exp $

DISTNAME=	aiosmtpd-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiosmtpd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/aiosmtpd/
COMMENT=	Reimplementation of the Python stdlib smtpd.py based on asyncio
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-atpublic-[0-9]*:../../devel/py-atpublic

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} aiosmtpd aiosmtpd${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
