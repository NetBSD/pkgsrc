# $NetBSD: Makefile,v 1.32 2002/03/13 17:37:19 fredb Exp $
#

DISTNAME=	xsane-0.80
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

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.xsane.org/
COMMENT=	New improved frontend for SANE

BUILD_USES_MSGFMT=	yes
BUILDLINK_DEPENDS.gtk?= gtk+>=1.2.5
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png>=1.2.1:../../graphics/png
DEPENDS+=	tiff-[0-9]*:../../graphics/tiff
DEPENDS+=	gimp>=1.0.4:../../graphics/gimp
DEPENDS+=	sane-backends>=1.0.4:../../graphics/sane-backends

USE_LIBINTL=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X11BASE=	YES

LDFLAGS+=	-L${PREFIX}/lib/sane -Wl,-R${PREFIX}/lib/sane
CPPFLAGS+=	-I${PREFIX}/include -I${LOCALBASE}/include
LIBS=		-lintl

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
