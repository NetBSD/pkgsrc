# $NetBSD: Makefile,v 1.4 2015/09/13 09:33:08 wiz Exp $

DISTNAME=	atomicwrites-0.1.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_PYPI:=a/atomicwrites/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/atomicwrites/
COMMENT=	Python module for atomic file writes on POSIX
LICENSE=	mit

EXTRACT_USING=	bsdtar	# gtar cannot handle pre-1970 timestamps

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
