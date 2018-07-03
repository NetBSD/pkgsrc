# $NetBSD: Makefile,v 1.3 2018/07/03 05:03:11 adam Exp $

DISTNAME=	flufl.lock-3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flufl.lock/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/flufl.lock/
COMMENT=	NFS-safe file locking with timeouts for POSIX systems
LICENSE=	apache-2.0

PYTHON_VERSIONS_ACCEPTED=	37 36 35 34

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
