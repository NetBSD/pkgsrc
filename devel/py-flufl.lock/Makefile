# $NetBSD: Makefile,v 1.8 2023/05/11 20:43:23 markd Exp $

DISTNAME=	flufl.lock-7.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flufl.lock/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/flufl.lock/
COMMENT=	NFS-safe file locking with timeouts for POSIX systems
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend-[0-9]*:../../devel/py-pdm_backend

PYTHON_VERSIONS_INCOMPATIBLE=	27

# fixup wrong WHEEL_INFODIR
post-install:
	mv ${DESTDIR}${PREFIX}/${PYSITELIB}/${WHEEL_NAME:S/./_/}.dist-info \
		${DESTDIR}${PREFIX}/${PYSITELIB}/${WHEEL_NAME}.dist-info

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
