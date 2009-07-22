# $NetBSD: Makefile,v 1.20 2009/07/22 12:55:20 wiz Exp $
#

DISTNAME=		pycairo-1.8.6
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py//}
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
PYTHON_VERSIONS_ACCEPTED= 26 25 24
PY_PATCHPLIST=		yes

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-2*)
BUILDLINK_TRANSFORM+=	rm:-std=c99
.endif

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.8.4nb1

.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
