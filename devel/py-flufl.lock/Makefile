# $NetBSD: Makefile,v 1.2 2018/05/18 13:12:20 fhajny Exp $

DISTNAME=	flufl.lock-3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flufl.lock/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/flufl.lock/
COMMENT=	NFS-safe file locking with timeouts for POSIX systems
LICENSE=	apache-2.0

PYTHON_VERSIONS_ACCEPTED=	36 35 34

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
