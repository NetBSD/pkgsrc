# $NetBSD: Makefile,v 1.43 2017/12/19 13:09:09 adam Exp $

DISTNAME=	py-notify-0.3.1
PKGNAME=	${DISTNAME:S/^py/${PYPKGPREFIX}/1}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/py-notify/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://home.gna.org/py-notify/
COMMENT=	Python package providing tool for observer programming pattern
LICENSE=	gnu-lgpl-v2.1

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.3.1

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
