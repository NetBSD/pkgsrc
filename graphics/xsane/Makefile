# $NetBSD: Makefile,v 1.87 2011/02/01 10:31:53 wiz Exp $

DISTNAME=	xsane-0.994
PKGNAME=	xsane-0.99.4
PKGREVISION=	13
CATEGORIES=	graphics
MASTER_SITES=	http://www.xsane.org/download/old/ \
		ftp://ftp.u-aizu.ac.jp/pub/misc/device/scsi/scanner/sane/xsane/ \
		ftp://sunsite.uio.no/pub/sane/xsane/ \
		ftp://ftp.informatik.uni-oldenburg.de/pub/sane/xsane/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.xsane.org/
COMMENT=	New improved frontend for SANE
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake msgfmt pkg-config
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/gimp/buildlink3.mk"
.include "../../graphics/sane-backends/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
