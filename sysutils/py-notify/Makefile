# $NetBSD: Makefile,v 1.40 2017/01/01 14:43:58 wiz Exp $

DISTNAME=	py-notify-0.2.1
PKGNAME=	${DISTNAME:S/py/${PYPKGPREFIX}/1}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES= 	http://download.gna.org/py-notify/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://home.gna.org/py-notify/
COMMENT=	Python package providing tool for observer programming pattern
LICENSE=	gnu-lgpl-v2.1

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 0.2.1

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
