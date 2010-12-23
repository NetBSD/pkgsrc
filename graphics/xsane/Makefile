# $NetBSD: Makefile,v 1.85 2010/12/23 11:44:47 dsainty Exp $

DISTNAME=	xsane-0.994
PKGNAME=	xsane-0.99.4
PKGREVISION=	12
CATEGORIES=	graphics
MASTER_SITES=	http://www.xsane.org/download/old/ \
		ftp://ftp.u-aizu.ac.jp/pub/misc/device/scsi/scanner/sane/xsane/ \
		ftp://sunsite.uio.no/pub/sane/xsane/ \
		ftp://ftp.informatik.uni-oldenburg.de/pub/sane/xsane/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.xsane.org/
COMMENT=	New improved frontend for SANE

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
