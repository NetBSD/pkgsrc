# $NetBSD: Makefile,v 1.14 2002/06/15 18:35:13 dmcmahill Exp $
#

DISTNAME=	rrdtool-1.0.33
PKGREVISION=	1
CATEGORIES=	databases graphics net
MASTER_SITES=	http://ee-staff.ethz.ch/~oetiker/webtools/rrdtool/pub/

MAINTAINER=	wulf@ping.net.au
HOMEPAGE=	http://ee-staff.ethz.ch/~oetiker/webtools/rrdtool
COMMENT=	Data analysis tool generating graphical representations

DEPENDS+=	cgilib-0.5:../../www/cgilib
DEPENDS+=	gd>=1.8.4nb1:../../graphics/gd
DEPENDS+=	jpeg-6*:../../graphics/jpeg

#needs FPC code not found in older versions of NetBSD
NOT_FOR_PLATFORM=	NetBSD-1.[0-4]*-alpha NetBSD-1.5-alpha \
			NetBSD-1.5.*-alpha NetBSD-1.5[A-U]-alpha

USE_LIBTOOL=	# defined
USE_GMAKE=	# defined
USE_X11=	# defined
GNU_CONFIGURE=	# defined

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

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
