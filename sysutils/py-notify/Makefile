# $NetBSD: Makefile,v 1.44 2022/01/10 18:49:22 wiz Exp $

DISTNAME=	py-notify-0.3.1
PKGNAME=	${DISTNAME:S/^py/${PYPKGPREFIX}/1}
PKGREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/py-notify/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://home.gna.org/py-notify/
COMMENT=	Python package providing tool for observer programming pattern
LICENSE=	gnu-lgpl-v2.1

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.3.1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
