# $NetBSD: Makefile,v 1.18 2000/08/28 15:18:53 rh Exp $
# FreeBSD Id: Makefile,v 1.3 1998/04/30 02:38:03 obrien Exp
#

DISTNAME=       sane-1.0.3
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.mostang.com/pub/sane/ \
		ftp://gd.tuwien.ac.at/hci/sane/ \
		ftp://metalab.unc.edu/pub/Linux/apps/graphics/capture/ \
		ftp://metalab.unc.edu/pub/Linux/Incoming/ \
		ftp://ftp.u-aizu.ac.jp/pub/misc/device/scsi/scanner/sane/ \
		http://gd.tuwien.ac.at/hci/sane/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mostang.com/sane/

DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	gimp>=1.0.4:../../graphics/gimp-current

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X11BASE=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig

# -O to workaorund bug with -O2 and egcs.
CFLAGS=		-O -I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
