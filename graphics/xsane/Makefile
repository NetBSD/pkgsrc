# $NetBSD: Makefile,v 1.160 2026/01/27 08:39:51 wiz Exp $

DISTNAME=	xsane-0.999
PKGNAME=	xsane-0.99.9
PKGREVISION=	45
CATEGORIES=	graphics
#MASTER_SITES=	http://www.xsane.org/download/
MASTER_SITES=	https://ftp.osuosl.org/pub/blfs/conglomeration/xsane/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.xsane.org/
COMMENT=	New improved frontend for SANE
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake msgfmt pkg-config
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--disable-gimp
CONFIGURE_ARGS+=	--disable-gimp2

.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-14.*) || !empty(CC_VERSION:Mgcc-15.*)
CFLAGS+=		-Wno-implicit-function-declaration
CFLAGS+=		-Wno-incompatible-pointer-types
.endif

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
