# $NetBSD: Makefile,v 1.18 2000/08/28 16:00:18 rh Exp $
#

DISTNAME=	xsane-0.61
CATEGORIES=	graphics
MASTER_SITES=	http://www.wolfsburg.de/~rauch/sane/ \
		http://gd.tuwien.ac.at/hci/sane/xsane/ \
		ftp://ftp.mostang.com/pub/sane/xsane/ \
		ftp://ftp.informatik.uni-oldenburg.de/pub/sane/xsane/ \
		ftp://gd.tuwien.ac.at/hci/sane/xsane/ \
		ftp://ftp.u-aizu.ac.jp/pub/misc/device/scsi/scanner/sane/xsane/ \
		ftp://ftp.umax.co.uk/sane/ \
		ftp://sunsite.uio.no/pub/sane/xsane/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.wolfsburg.de/~rauch/sane/sane-xsane.html

DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png>=1.0.6:../../graphics/png
DEPENDS+=	tiff-*:../../graphics/tiff
DEPENDS+=	sane>=1.0.3:../../graphics/sane

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X11BASE=	YES

LDFLAGS+=	-L${PREFIX}/lib/sane -Wl,-R${PREFIX}/lib/sane
INCLUDES=	-I${PREFIX}/include -I${LOCALBASE}/include
CPPFLAGS+=	${INCLUDES}
CONFIGURE_ENV+=	INCLUDES="${INCLUDES}"

.include "../../mk/bsd.pkg.mk"
