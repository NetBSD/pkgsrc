# $NetBSD: Makefile,v 1.1 2021/05/08 09:14:20 adam Exp $

DISTNAME=	pid-3.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pid/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/trbs/pid
COMMENT=	Pidfile featuring stale detection and file-locking
LICENSE=	apache-2.0

TEST_DEPENDS+=	${PYPKGPREFIX}-nose>=1.0:../../devel/py-nose

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	pytest

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
