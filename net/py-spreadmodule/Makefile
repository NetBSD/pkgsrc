# $NetBSD: Makefile,v 1.19 2017/09/03 08:53:13 wiz Exp $

DISTNAME=	SpreadModule-1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/SpreadModule/spreadmodule/}
PKGREVISION=	3
CATEGORIES=	net python
MASTER_SITES=	https://www.python.org/other/spread/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.python.org/other/spread/
COMMENT=	Python bindings for the Spread messaging service
LICENSE=	python-software-foundation

SUBST_CLASSES+=		setup
SUBST_STAGE.setup=	post-patch
SUBST_FILES.setup=	setup.py
SUBST_SED.setup=	-e 's,/usr/local,${BUILDLINK_PREFIX.spread},g'

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 1.4

.include "../../net/spread/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
