# $NetBSD: Makefile,v 1.4 2000/06/01 11:23:19 rh Exp $
#

DISTNAME=	rrdtool-1.0.21
CATEGORIES=	databases graphics net
MASTER_SITES=	http://ee-staff.ethz.ch/~oetiker/webtools/rrdtool/pub/

MAINTAINER=	wulf@ping.net.au
HOMEPAGE=	http://ee-staff.ethz.ch/~oetiker/webtools/rrdtool

DEPENDS+=	cgilib-0.5:../../www/cgilib
DEPENDS+=	gd>=1.7.3:../../graphics/gd
DEPENDS+=	jpeg-6*:../../graphics/jpeg

USE_PERL5=	yes
USE_PKGLIBTOOL=	yes
USE_GMAKE=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ARGS= --enable-shared

# tcl build not enabled at this time.  If this is turned on, the
# following files & directory would have to be added to PLIST:
#
# lib/tclrrd1.0.21.so
# lib/tclrrd1.0.21/
# lib/tclrrd1.0.21/pkgIndex.tcl
#
#DEPENDS+=	tcl-8.0.5:../../x11/tk
#
#CFLAGS+=		-I${LOCALBASE}/include/tcl8.0
#CONFIGURE_ENV+= 	CFLAGS="${CFLAGS}"
#CONFIGURE_ARGS+=	--with-tcllib=${LOCALBASE}/lib/tcl8.0
#INSTALL_TARGET= 	install site-tcl-install

.include "../../mk/bsd.pkg.mk"
