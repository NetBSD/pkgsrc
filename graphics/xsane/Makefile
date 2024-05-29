# $NetBSD: Makefile,v 1.146 2024/05/29 16:33:04 adam Exp $

DISTNAME=	xsane-0.999
PKGNAME=	xsane-0.99.9
PKGREVISION=	32
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

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/gimp/buildlink3.mk"
.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
