# $NetBSD: Makefile,v 1.47 2004/10/03 00:14:59 tv Exp $

DISTNAME=	xsane-0.93
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.xsane.org/download/ \
		http://gd.tuwien.ac.at/hci/sane/xsane/ \
		ftp://ftp.mostang.com/pub/sane/xsane/ \
		ftp://ftp.no.mostang.com/pub/sane/xsane/ \
		ftp://ftp.de.mostang.com/pub/sane/xsane/ \
		ftp://gd.tuwien.ac.at/hci/sane/xsane/ \
		ftp://ftp.u-aizu.ac.jp/pub/misc/device/scsi/scanner/sane/xsane/ \
		ftp://sunsite.uio.no/pub/sane/xsane/ \
		ftp://ftp.informatik.uni-oldenburg.de/pub/sane/xsane/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.xsane.org/
COMMENT=	New improved frontend for SANE

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
GNU_CONFIGURE=		YES

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/gimp/buildlink3.mk"
.include "../../graphics/sane-backends/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
