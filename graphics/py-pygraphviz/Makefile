# $NetBSD: Makefile,v 1.31 2026/09/08 13:04:51 adam Exp $

DISTNAME=	pygraphviz-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pygraphviz/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pygraphviz.github.io/
COMMENT=	Python interface to the Graphviz package
LICENSE=	original-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_TOOLS+=	pkg-config

SUBST_CLASSES+=		libpath
SUBST_STAGE.libpath=	pre-configure
SUBST_MESSAGE.libpath=	Fixing absolute paths.
SUBST_FILES.libpath=	setup.py
SUBST_SED.libpath=	-e 's,"/usr/local,"${PREFIX},g'

pre-configure:
	${LN} -fs ${TOOLBASE}/bin/swig4.0 ${BUILDLINK_DIR}/bin/swig

.include "../../devel/swig4/buildlink3.mk"
.include "../../graphics/graphviz/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
