# $NetBSD: Makefile,v 1.2 2014/01/31 19:32:04 wiz Exp $

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
PYTHON_VERSIONED_DEPENDENCIES=	dateutil

.include "options.mk"

.include "../../graphics/librsvg/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
