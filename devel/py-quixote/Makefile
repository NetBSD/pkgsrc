# $NetBSD: Makefile,v 1.10 2018/03/24 08:20:06 adam Exp $

DISTNAME=	Quixote-2.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel www python
MASTER_SITES=	http://quixote.ca/releases/

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://quixote.ca/
COMMENT=	Framework for writing Python web application
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # v3.0 is for Python 3.x only

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
