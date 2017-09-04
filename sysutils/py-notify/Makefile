# $NetBSD: Makefile,v 1.42 2017/09/04 18:55:09 wiz Exp $

DISTNAME=	py-notify-0.2.1
PKGNAME=	${DISTNAME:S/py/${PYPKGPREFIX}/1}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES= 	http://download.gna.org/py-notify/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://pypi.python.org/pypi/py-notify/
COMMENT=	Python package providing tool for observer programming pattern
LICENSE=	gnu-lgpl-v2.1

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 0.2.1

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
