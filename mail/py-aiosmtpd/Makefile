# $NetBSD: Makefile,v 1.1 2017/04/25 17:16:57 fhajny Exp $

DISTNAME=	aiosmtpd-1.0a5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiosmtpd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/aiosmtpd/
COMMENT=	Reimplementation of the Python stdlib smtpd.py based on asyncio
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-atpublic-[0-9]*:../../devel/py-atpublic

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} smtpd smtpd${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
