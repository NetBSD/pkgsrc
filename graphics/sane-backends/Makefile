# $NetBSD: Makefile,v 1.2 2001/02/24 19:08:37 tron Exp $
# FreeBSD Id: Makefile,v 1.3 1998/04/30 02:38:03 obrien Exp
#

DISTNAME=       sane-backends-1.0.4
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.mostang.com/pub/sane/ \
		ftp://gd.tuwien.ac.at/hci/sane/ \
		ftp://metalab.unc.edu/pub/Linux/apps/graphics/capture/ \
		ftp://metalab.unc.edu/pub/Linux/Incoming/ \
		ftp://ftp.u-aizu.ac.jp/pub/misc/device/scsi/scanner/sane/ \
		ftp://ftp.informatik.uni-oldenburg.de/pub/sane/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mostang.com/sane/
COMMENT=	API for access to scanners, digitals camera, frame grabbers etc

DEPENDS+=	jpeg-6b:../../graphics/jpeg

CONFLICTS+=	sane<=1.0.3

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
#USE_X11BASE=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig
CONFIGURE_ENV+=	CPPFLAGS="-I${PREFIX}/include"

# -O to work around a bug with -O2 and egcs.
CFLAGS=		-O -I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
