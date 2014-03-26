# $NetBSD: Makefile,v 1.4 2014/03/26 10:28:49 wiz Exp $

DISTNAME=	keyring-0.5.1
PKGNAME=	${PYPKGPREFIX}-keyring-0.5.1
CATEGORIES=	security
MASTER_SITES=	http://pypi.python.org/packages/source/k/keyring/

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/keyring
COMMENT=	Store and access your passwords safely
LICENSE=	python-software-foundation

PYDISTUTILSPKG= yes
PYTHON_VERSIONS_INCOMPATIBLE=	33

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
