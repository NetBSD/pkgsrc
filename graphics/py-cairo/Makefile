# $NetBSD: Makefile,v 1.81 2023/11/14 16:05:46 wiz Exp $

DISTNAME=	pycairo-1.25.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycairo/}

MAINTAINER=	leuzi@trash.net
HOMEPAGE=	https://cairographics.org/pycairo/
COMMENT=	Python bindings for cairo
LICENSE=	gnu-lgpl-v2.1 OR mpl-1.1

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_TOOLS+=	pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_SELF_CONFLICT=		yes
PY_PATCHPLIST=			yes

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.13.1
.include "../../graphics/cairo/buildlink3.mk"
#.include "../../lang/python/egg.mk"
MESON_REQD+=	1.2.0
.include "../../devel/meson/build.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
