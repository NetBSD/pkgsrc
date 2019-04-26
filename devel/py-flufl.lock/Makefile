# $NetBSD: Makefile,v 1.4 2019/04/26 12:44:43 roy Exp $

DISTNAME=	flufl.lock-3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flufl.lock/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/flufl.lock/
COMMENT=	NFS-safe file locking with timeouts for POSIX systems
LICENSE=	apache-2.0

PYTHON_VERSIONS_ACCEPTED=	37 36

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
