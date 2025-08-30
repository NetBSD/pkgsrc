# $NetBSD: Makefile,v 1.157 2025/08/30 22:45:37 wiz Exp $

DISTNAME=	xsane-0.999
PKGNAME=	xsane-0.99.9
PKGREVISION=	43
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

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
