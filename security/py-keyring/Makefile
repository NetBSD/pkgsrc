# $NetBSD: Makefile,v 1.5 2014/03/31 08:29:11 wiz Exp $

DISTNAME=	keyring-3.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	http://pypi.python.org/packages/source/k/keyring/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/keyring
COMMENT=	Store and access your passwords safely
LICENSE=	python-software-foundation

REPLACE_PYTHON+=	keyring/cli.py

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
