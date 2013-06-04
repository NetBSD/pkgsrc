# $NetBSD: Makefile,v 1.40 2013/06/04 22:16:25 tron Exp $
#

DISTNAME=		py2cairo-1.8.10
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py2//}
PKGREVISION=		8
CATEGORIES=		graphics
MASTER_SITES=		http://cairographics.org/releases/

MAINTAINER=		leuzi@trash.net
HOMEPAGE=		http://cairographics.org/pycairo/
COMMENT=		Python bindings for cairo
LICENSE=		gnu-lgpl-v2.1 OR mpl-1.1

WRKSRC=			${WRKDIR}/${DISTNAME:S/py2/py/}

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}

PKGCONFIG_OVERRIDE+=	pycairo.pc.in
PY_PATCHPLIST=		yes

PYTHON_SELF_CONFLICT=	yes

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-2*) || \
    ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+=	rm:-std=c99
.endif

.include "../../lang/python/extension.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.8.10
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
