# $NetBSD: Makefile,v 1.112 2014/12/26 23:21:10 mef Exp $

DISTNAME=	xsane-0.998
PKGNAME=	xsane-0.99.8
PKGREVISION=	19
CATEGORIES=	graphics
MASTER_SITES=	http://www.xsane.org/download/ \
		ftp://ftp.u-aizu.ac.jp/pub/misc/device/scsi/scanner/sane/xsane/ \
		ftp://sunsite.uio.no/pub/sane/xsane/ \
		ftp://ftp.informatik.uni-oldenburg.de/pub/sane/xsane/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xsane.org/
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
