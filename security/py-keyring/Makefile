# $NetBSD: Makefile,v 1.3 2014/01/25 10:30:20 wiz Exp $

DISTNAME=	keyring-0.5.1
PKGNAME=	${PYPKGPREFIX}-keyring-0.5.1
CATEGORIES=	security
MASTER_SITES=	http://pypi.python.org/packages/source/k/keyring/

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://pypi.python.org/packages/source/k/keyring/
COMMENT=	Store and access your passwords safely
LICENSE=	python-software-foundation

PYDISTUTILSPKG= yes
PYTHON_VERSIONS_INCOMPATIBLE=	33

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
