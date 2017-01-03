# $NetBSD: Makefile,v 1.18 2017/01/03 13:23:03 jperkin Exp $

DISTNAME=	keyring-5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PYPI:=k/keyring/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/keyring
COMMENT=	Store and access your passwords safely
LICENSE=	python-software-foundation

BUILD_DEPENDS+=	${PYPKGPREFIX}-hgtools>=5.0:../../devel/py-hgtools

REPLACE_PYTHON+=	keyring/cli.py

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/keyring ${DESTDIR}${PREFIX}/bin/keyring-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
