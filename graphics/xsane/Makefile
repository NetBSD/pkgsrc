# $NetBSD: Makefile,v 1.36 2002/12/01 13:49:42 salo Exp $
#

DISTNAME=	xsane-0.86
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

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.xsane.org/
COMMENT=	New improved frontend for SANE

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_X11BASE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/gimp-base/buildlink2.mk"
.include "../../graphics/sane-backends/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
