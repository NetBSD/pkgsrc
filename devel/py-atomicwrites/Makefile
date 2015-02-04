# $NetBSD: Makefile,v 1.1 2015/02/04 11:54:19 wiz Exp $

DISTNAME=	atomicwrites-0.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time
MASTER_SITES=	https://pypi.python.org/packages/source/a/atomicwrites/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/atomicwrites/
COMMENT=	Python module for atomic file writes on POSIX
LICENSE=	mit

EXTRACT_USING=	bsdtar	# gtar cannot handle pre-1970 timestamps

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
