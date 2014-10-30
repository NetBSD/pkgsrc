# $NetBSD: Makefile,v 1.1 2014/10/30 13:50:41 fhajny Exp $

DISTNAME=	argcomplete-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	https://pypi.python.org/packages/source/a/argcomplete/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	https://github.com/kislyuk/argcomplete/
COMMENT=	Bash tab completion for argparse
LICENSE=	apache-2.0

PYTHON_VERSIONS_INCOMPATIBLE=	26

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
