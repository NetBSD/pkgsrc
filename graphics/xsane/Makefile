# $NetBSD: Makefile,v 1.26 2001/05/22 09:32:23 wiz Exp $
#

DISTNAME=	xsane-0.72
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
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	gtk+>=1.2.5:../../x11/gtk
DEPENDS+=	png>=1.0.11:../../graphics/png
DEPENDS+=	tiff-*:../../graphics/tiff
DEPENDS+=	gimp>=1.0.4:../../graphics/gimp
DEPENDS+=	sane-backends>=1.0.4:../../graphics/sane-backends

USE_LIBINTL=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X11BASE=	YES

LDFLAGS+=	-L${PREFIX}/lib/sane -Wl,-R${PREFIX}/lib/sane
INCLUDES=	-I${PREFIX}/include -I${LOCALBASE}/include
CPPFLAGS+=	${INCLUDES}
CONFIGURE_ENV+=	CPPFLAGS="${INCLUDES}" LIBS="-lintl"

.include "../../mk/bsd.pkg.mk"
