# $NetBSD: Makefile,v 1.23 2010/06/13 22:44:42 wiz Exp $
#

DISTNAME=		pycairo-1.8.8
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		http://cairographics.org/releases/

MAINTAINER=		leuzi@trash.net
HOMEPAGE=		http://cairographics.org/pycairo/
COMMENT=		Python bindings for cairo
LICENSE=		gnu-lgpl-v2.1 OR mpl-v1.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}

PKGCONFIG_OVERRIDE+=	pycairo.pc.in
PYTHON_VERSIONS_ACCEPTED= 26 25
PY_PATCHPLIST=		yes

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-2*)
BUILDLINK_TRANSFORM+=	rm:-std=c99
.endif

.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.8.8
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
