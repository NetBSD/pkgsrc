# $NetBSD: Makefile,v 1.16 2000/06/01 11:23:32 rh Exp $
#

DISTNAME=	xsane-0.51
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
DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	sane-1.0.1:../../graphics/sane

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X11BASE=	YES
USE_PKGLIBTOOL=	YES

CPPFLAGS+=	-I${PREFIX}/include -I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
