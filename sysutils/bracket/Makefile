# $NetBSD: Makefile,v 1.4 2023/10/23 06:37:52 wiz Exp $

DISTNAME=	bracket-2.18
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	https://www.gson.org/netbsd/bracket/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	#
COMMENT=	Framework for running NetBSD builds and tests
LICENSE=	isc

DEPENDS+=	${PYPKGPREFIX}-anita-[0-9]*:../../misc/py-anita
DEPENDS+=	qemu-[0-9]*:../../emulators/qemu
DEPENDS+=	rsync-[0-9]*:../../net/rsync
DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-sysctl-[0-9]*:../../devel/py-sysctl
DEPENDS+=	${PYPKGPREFIX}-gitpython-[0-9]*:../../devel/py-gitpython
DEPENDS+=	${PYPKGPREFIX}-mercurial-[0-9]*:../../devel/py-mercurial

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c++

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN}

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "options.mk"

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
