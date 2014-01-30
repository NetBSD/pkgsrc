# $NetBSD: Makefile,v 1.1 2014/01/30 03:46:18 rodent Exp $

DISTNAME=	tryton-3.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://downloads.tryton.org/3.0/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Three-tiers high-level general purpose application platform
LICENSE=	gnu-gpl-v3

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

PYTHON_VERSIONS_INCOMPATIBLE=	26 # XXX Needs weakrefset. No package, though.

.include "options.mk"

.include "../../lang/python/pyversion.mk"

.if ${PYPACKAGE} == "python27"
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
.else
DEPENDS+=	${PYPKGPREFIX}-dateutil2-[0-9]*:../../time/py-dateutil2
.endif
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
