# $NetBSD: Makefile,v 1.4 2014/05/09 07:37:01 wiz Exp $

DISTNAME=	filechunkio-1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/f/filechunkio/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/fabian/filechunkio
COMMENT=	Chunck files for input/output
LICENSE=	mit

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 1.5

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
