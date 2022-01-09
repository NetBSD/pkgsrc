# $NetBSD: Makefile,v 1.6 2022/01/09 00:28:58 tnn Exp $

GITHUB_RELEASE=	${PKGVERSION_NOREV}
DISTNAME=	libva-utils-2.13.0
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=intel/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/intel/libva-utils/
COMMENT=	Collection of tests for VA-API
LICENSE=	mit

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-x11
# Might be useful to have this but I'll leave it to
# someone else to enable. -tnn
CONFIGURE_ARGS+=	--disable-wayland

SUBST_CLASSES+=		getopt
SUBST_STAGE.getopt=	pre-configure
SUBST_MESSAGE.getopt=	Fixing getopt_long_only
SUBST_FILES.getopt+=	encode/*.c
SUBST_SED.getopt+=	-e 's,getopt_long_only,getopt_long,'

LIBS+=	-lm
# Need explicit pthread linkage due to dlopening libraries
# that link with pthread.
LIBS.NetBSD+= -lpthread

BUILDLINK_API_DEPENDS.libva+=	libva>=${PKGVERSION_NOREV}
.include "../../multimedia/libva/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
