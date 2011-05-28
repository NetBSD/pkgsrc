# $NetBSD: Makefile,v 1.14 2011/05/28 09:07:38 obache Exp $

.include "../../print/ja-vflib-lib/Makefile.common"

PKGNAME=	ja-vflib-utils-${VFLIB_VERSION}
PKGREVISION=	3
COMMENT=	Utilities for manipulating VFlib vector font files

BUILDLINK_API_DEPENDS.vflib+=	ja-vflib-lib>=${VFLIB_VERSION}

CONFIGURE_ARGS+=	--enable-tools --with-x

USE_TOOLS+=	xmkmf

BUILD_TARGET=		build-tools
INSTALL_TARGET=		install-tools

INSTALLATION_DIRS+=	bin

.include "../../print/ja-vflib-lib/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
