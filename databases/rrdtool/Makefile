# $NetBSD: Makefile,v 1.10 2001/05/06 01:09:34 fredb Exp $
#

DISTNAME=	rrdtool-1.0.28
CATEGORIES=	databases graphics net
MASTER_SITES=	http://ee-staff.ethz.ch/~oetiker/webtools/rrdtool/pub/

MAINTAINER=	wulf@ping.net.au
HOMEPAGE=	http://ee-staff.ethz.ch/~oetiker/webtools/rrdtool
COMMENT=	Data analysis tool generating graphical representations

DEPENDS+=	cgilib-0.5:../../www/cgilib
DEPENDS+=	gd>=1.7.3:../../graphics/gd
DEPENDS+=	jpeg-6*:../../graphics/jpeg

# IEEE math not good enough on alpha
NOT_FOR_PLATFORM=	NetBSD-*-alpha

USE_LIBTOOL=	# defined
USE_GMAKE=	# defined
USE_X11=	# defined
GNU_CONFIGURE=	# defined

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ARGS= --enable-shared

MAKE_ENV+=	X11BASE=${X11BASE} X11PREFIX=${X11PREFIX}

USE_PERL5=		# defined
PERL5_PACKLIST+= 	${PERL5_SITEARCH}/auto/RRDp/.packlist
PERL5_PACKLIST+=	${PERL5_SITEARCH}/auto/RRDs/.packlist

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
