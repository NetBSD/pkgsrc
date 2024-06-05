# $NetBSD: Makefile,v 1.11 2024/06/05 22:44:57 wiz Exp $

DISTNAME=	argparse-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/argparse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ThomasWaldmann/argparse
COMMENT=	Easy, declarative interface for creating command line tools
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

PYTHON_27_ACCEPTED=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
