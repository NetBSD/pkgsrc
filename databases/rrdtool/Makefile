# $NetBSD: Makefile,v 1.2 1999/11/18 15:57:23 wennmach Exp $
#

DISTNAME=	rrdtool-1.0.7
CATEGORIES=	databases graphics net
MASTER_SITES=	http://ee-staff.ethz.ch/~oetiker/webtools/rrdtool/pub/

MAINTAINER=	wulf@ping.net.au
HOMEPAGE=	http://ee-staff.ethz.ch/~oetiker/webtools/rrdtool

DEPENDS+=	cgilib-0.5:../../www/cgilib
DEPENDS+=	gd-1.7.3:../../graphics/gd

USE_PERL5=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ARGS= --enable-shared

.include "../../mk/bsd.pkg.mk"
