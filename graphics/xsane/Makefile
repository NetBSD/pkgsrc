# $NetBSD: Makefile,v 1.19 2000/11/04 23:36:12 veego Exp $
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

BUILD_DEPENDS+=	msgfmt:../../devel/gettext
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png>=1.0.6:../../graphics/png
DEPENDS+=	tiff-*:../../graphics/tiff
DEPENDS+=	sane>=1.0.3:../../graphics/sane

USE_LIBINTL=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X11BASE=	YES

LDFLAGS+=	-L${PREFIX}/lib/sane -Wl,-R${PREFIX}/lib/sane
INCLUDES=	-I${PREFIX}/include -I${LOCALBASE}/include
CPPFLAGS+=	${INCLUDES}
CONFIGURE_ENV+=	INCLUDES="${INCLUDES}" LIBS="-lintl"

.include "../../mk/bsd.pkg.mk"
