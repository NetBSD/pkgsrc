# $NetBSD: Makefile,v 1.11 1999/02/19 14:31:44 rh Exp $
# FreeBSD Id: Makefile,v 1.3 1998/04/30 02:38:03 obrien Exp
#

DISTNAME=       sane-1.00
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.mostang.com/pub/sane/ \
		ftp://gd.tuwien.ac.at/hci/sane/ \
		ftp://ftp.u-aizu.ac.jp/pub/misc/device/scsi/scanner/sane/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mostang.com/sane/

DEPENDS+=	gtk10-1.0.6:../../x11/gtk10
DEPENDS+=	gimp-1.0.2:../../graphics/gimp

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X11BASE=	yes
CONFIGURE_ENV+=	GTK_CONFIG="${X11BASE}/bin/gtk10-config"

# -O to workaorund bug with -O2 and egcs.
CFLAGS=		-O -I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
