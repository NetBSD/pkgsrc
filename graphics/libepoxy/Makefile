# $NetBSD: Makefile,v 1.1 2015/04/03 08:48:57 tnn Exp $

DISTNAME=	libepoxy-1.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=anholt/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/anholt/libepoxy/
COMMENT=	Library for OpenGL function pointer management
LICENSE=	mit

USE_TOOLS+=	pkg-config autoconf autoreconf automake
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
PYTHON_FOR_BUILD_ONLY=	yes

PKGCONFIG_OVERRIDE+=	epoxy.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "modular"
# We should enforce this, but the dependency cannot
# currently be satisfied by pkgsrc, which might break pbulk(?)
# We'll settle for failing in the build phase for now.
#BUILDLINK_API_DEPENDS.MesaLib+=	MesaLib>=10
.else
PKG_FAIL_REASON+=	"This package is currently for modular X.org only"
.endif

.include "../../lang/python/tool.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
