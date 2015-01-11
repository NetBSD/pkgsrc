# $NetBSD: Makefile,v 1.8 2015/01/11 20:59:56 wiz Exp $

DISTNAME=	keyring-4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://pypi.python.org/packages/source/k/keyring/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/keyring
COMMENT=	Store and access your passwords safely
LICENSE=	python-software-foundation

REPLACE_PYTHON+=	keyring/cli.py
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/keyring ${DESTDIR}${PREFIX}/bin/keyring-${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
